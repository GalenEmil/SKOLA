from flask import Flask, request, jsonify
from flask_restful import Resource, Api
from flask_sqlalchemy import SQLAlchemy
from flask_cors import CORS
from passlib.hash import bcrypt
from flask_jwt_extended import (
    JWTManager,
    create_access_token,
    jwt_required,
    get_jwt_identity
)
from datetime import datetime
import re

app = Flask(__name__)
api = Api(app)
CORS(app)

# ------------------------------------------------
# Configuration
# ------------------------------------------------
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///mydatabase.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
app.config['JWT_SECRET_KEY'] = 'YOUR_SECRET_KEY_HERE'
app.config['JWT_VERIFY_SUB'] = False  # Example usage
db = SQLAlchemy(app)
jwt = JWTManager(app)

# ------------------------------------------------
# Models
# ------------------------------------------------
class User(db.Model):
    __tablename__ = 'users'
    
    id = db.Column(db.Integer, primary_key=True)
    email = db.Column(db.String(120), unique=True, nullable=False)
    name = db.Column(db.String(120), nullable=False)
    password = db.Column(db.String(200), nullable=False)  # hashed password
    
    posts = db.relationship('Post', backref='user', lazy=True)


class Post(db.Model):
    __tablename__ = 'posts'
    
    id = db.Column(db.Integer, primary_key=True)
    title = db.Column(db.String(200), nullable=False)
    text = db.Column(db.Text, nullable=False)
    date = db.Column(db.DateTime, default=datetime.utcnow)
    user_id = db.Column(db.Integer, db.ForeignKey('users.id'), nullable=False)
    # AI gjort
    def to_dict(self):
        return {
            'id': self.id,
            'title': self.title,
            'text': self.text,
            'date': self.date.isoformat(),
            'user_id': self.user_id,
            'author_name': self.author.name  # Requires backref='author' in User model
        }

with app.app_context():
    db.create_all()

# ------------------------------------------------
# Helper functions
# ------------------------------------------------
def hash_password(password):
    """Hash a plaintext password using bcrypt."""
    return bcrypt.hash(password)

def verify_password(plaintext_password, hashed_password):
    """Verify a plaintext password against a hashed version."""
    return bcrypt.verify(plaintext_password, hashed_password)

# ------------------------------------------------
# Resources
# ------------------------------------------------
class RegisterResource(Resource):
    """
    Register a new user.
    Expects JSON:
    {
        "email": "test@example.com",
        "name": "John",
        "password": "mypassword"
    }
    """
    def post(self):
        data = request.get_json()
        if not data:
            return {"error": "No input data provided"}, 400

        email = data.get('email')
        name = data.get('name')
        password = data.get('password')
        
        if not (email and name and password):
            return {"error": "Missing email, name, or password"}, 400
        # Reg ex e-mail kontroll
        # Kontrollera giltig e-postadress
        email_regex = r"^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$"
        if not re.match(email_regex, email):
            return {"error": "Invalid email format"}, 400

        """
        pieces = email.split("@")
        if not len(pieces) == 2:
            return {"error": "Not a viable e-mail address, too many @"}, 400
        
        if not len(pieces[0]) < 2:
            return {"error": "Not a viable e-mail address, too few letters before @"}, 400
        
        if not len(pieces[1]) < 3:
            return {"error": "Not a viable e-mail address, too few letters after @"}, 400

        if not (email and name and password):
            return {"error": "Missing email, name, or password"}, 400
        
        # Kolla om det finns @ och . i epostadressen
        if not ("@" in email and "." in email):
            return {"error": "Not a viable e-mail address, missing @ or ."}, 400

        # Kolla om en e-post redan finns i databasen
        redanExisterandeKonto = db.session.query(User).filter(User.email == email).first()
        if redanExisterandeKonto:
            return {"error": "Account with that e-mail already exists"}, 400
        """
        # TODO: Lägg till felhantering. Vad mer kan gå
        # fel med denna metod? Tänk: Man vill helst inte skicka data
        # vidare till databasen om en databasoperation kommer att misslyckas,
        # för databasoperationer är ganska dyra. Man vill försöka "förutspå" fel
        # och avbryta innan databasoperationen, om servern vet att det blir ett fel.
        # KLAR

        # Create and save user
        new_user = User(
            email=email,
            name=name,
            password=hash_password(password)
        )
        db.session.add(new_user)
        db.session.commit()

        return {
            "message": "User registered successfully",
            "user_id": new_user.id
        }, 201


class LoginResource(Resource):
    """
    Log in a user.
    Expects JSON:
    {
        "email": "test@example.com",
        "password": "mypassword"
    }
    Returns: { "access_token": "<JWT>", "user_id": <id> }
    """
    def post(self):
        data = request.get_json()
        if not data:
            return {"error": "No input data provided"}, 400

        email = data.get('email')
        password = data.get('password')

        if not (email and password):
            return {"error": "Missing email or password"}, 400

        user = User.query.filter_by(email=email).first()
        if not user or not verify_password(password, user.password):
            return {"error": "Invalid email or password"}, 401

        access_token = create_access_token(identity=user.id)
        return {
            "access_token": access_token,
            "user_id": user.id
        }, 200


class UserResource(Resource):
    """
    Fetch a user's profile by their ID.
    Requires a valid JWT in the Authorization header: Bearer <token>
    """
    @jwt_required()
    def get(self, user_id):
        user = User.query.get_or_404(user_id)
        return {
            "id": user.id,
            "email": user.email,
            "name": user.name
        }, 200


class PostListResource(Resource):
    """
    - GET: Fetch the N latest posts. Query param `count` to control how many. Default = 5
    - POST: Create a new post. Requires JSON body and valid JWT.
    """
    def get(self):
        count = request.args.get('count', 5, type=int)
        posts = db.session.query(Post, User).join(User).order_by(Post.date.desc()).limit(count).all()
        
        results = []
        for p in posts:
            results.append({
                "id": p[0].id,
                "title": p[0].title,
                "text": p[0].text,
                "date": p[0].date.isoformat(),
                "user_id": p[0].user_id,
                "name": p[1].name
            })
        return results, 200

    @jwt_required()
    def post(self):
        """
        Create a new post.
        Requires JSON:
        {
            "title": "My Title",
            "text": "Post text here..."
        }
        and a valid JWT.
        """
        data = request.get_json()
        if not data:
            return {"error": "No input data provided"}, 400

        title = data.get('title')
        text = data.get('text')
        if not (title and text):
            return {"error": "Missing title or text"}, 400

        current_user_id = get_jwt_identity()
        new_post = Post(title=title, text=text, user_id=current_user_id)
        db.session.add(new_post)
        db.session.commit()

        return {
            "message": "Post created",
            "post_id": new_post.id
        }, 201


class UserPostsResource(Resource):
    """
    Fetch all posts by a specific user.
    """
    def get(self, user_id):
        # TODO: Lägg till kod för denna metod.
        # Den borde hämta en lista över Posts som tillhör
        # en specifik användare.
        # KLAR
        count = request.args.get('count', 5, type=int)
        posts = db.session.query(Post, User).filter(Post.user_id == user_id).join(User).order_by(Post.date.desc()).limit(count).all()
        
        results = []
        for p in posts:
            results.append({
                "id": p[0].id,
                "title": p[0].title,
                "text": p[0].text,
                "date": p[0].date.isoformat(),
                "user_id": p[0].user_id,
                "name": p[1].name
            })
        return results, 200


class PostResource(Resource):
    # Egengjort
    @jwt_required()
    def delete(self, post_id):
        # TODO: Lägg till kod för denna metod.
        # Den borde ta bort ett Post som har det angivna ID:et.
        # Access the identity of the current user with get_jwt_identity
        # KLAR
        access_token = get_jwt_identity()
        userpost = db.session.query(Post).filter(Post.id == post_id).first()
        if userpost != None:
            if userpost.user_id == access_token:
                db.session.delete(userpost)
                db.session.commit()
                return 200
        return {"message": "Method is not implemented"}, 200


# Lägg till denna route eller uppdatera befintlig PUT/PATCH-handler
@app.route('/api/posts/<int:post_id>', methods=['PUT'])
def update_post(post_id):
    data = request.get_json()
    # Här skulle du uppdatera posten i din databas
    # Exempel (anpassa till din ORM/databas):
    post = Post.query.get_or_404(post_id)
    post.title = data.get('title', post.title)
    post.text = data.get('text', post.text)
    db.session.commit()
    return jsonify(post.to_dict()), 200

# ------------------------------------------------
# Routes
# ------------------------------------------------
api.add_resource(RegisterResource, '/register')
api.add_resource(LoginResource, '/login')
api.add_resource(UserResource, '/user/<int:user_id>')

# Post-related routes
api.add_resource(PostListResource, '/posts')  # GET for latest, POST for creating
api.add_resource(PostResource, '/posts/<int:post_id>')
api.add_resource(UserPostsResource, '/user/<int:user_id>/posts')

# ------------------------------------------------
# Run the application
# ------------------------------------------------
if __name__ == '__main__':
    app.run(debug=True, port=9000)