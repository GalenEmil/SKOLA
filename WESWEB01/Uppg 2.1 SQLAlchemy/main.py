from flask import Flask, render_template, request, redirect, url_for, flash, session
from flask_sqlalchemy import SQLAlchemy
from werkzeug.security import generate_password_hash, check_password_hash
from datetime import datetime
import random

# Initialize the Flask app
app = Flask(__name__)
app.secret_key = 'your_secret_key'

# Configure SQLite database
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///users.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False

db = SQLAlchemy(app)

# Define the User model
class User(db.Model):
    # 1. Column
    # 2. Vilken datatyp det är
    # 3.
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(80), unique=True, nullable=False)
    password = db.Column(db.String(120), nullable=False)

# Define the DiceRoll model
class DiceRoll(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    user_id = db.Column(db.Integer, db.ForeignKey('user.id'), nullable=False)
    roll = db.Column(db.Integer, nullable=False)
    timestamp = db.Column(db.DateTime, default=datetime.utcnow, nullable=False)
    # Ska spara vilken sorts tärning man har valt i databasen 
    diceType = db.Column(db.integer, nullable=False)

# Create the database
with app.app_context():
    db.create_all()

# Route for the homepage
@app.route('/')
def home():
    return render_template('home.html', username=session.get('username'))

# Route for the login page
@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        user = User.query.filter_by(username=username).first()
        if user and check_password_hash(user.password, password):
            session['user_id'] = user.id
            session['username'] = user.username
            flash('Login successful!', 'success')
            return redirect(url_for('home'))
        else:
            flash('Invalid credentials. Please try again.', 'danger')
    return render_template('login.html')

# Route for the register page
@app.route('/register', methods=['GET', 'POST'])
def register():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        # query kollar i databasen
        # filter_by hämtar användarnamnet. I form av lista
        # first() tar då det första, och enda, namnet i listan
        # ["bob"]
        if User.query.filter_by(username=username).first():
            flash('Username already exists. Please choose another.', 'danger')
        else:
            # Hash får ut ett hash-värde av lösenordet
            # hash-värdet fungerar inte baklänges. Går inte att avkryptera
            # lösenord: "abc123" --> 04f23...
            # 04f23 --> ???
            # Detta för säkerhet
            hashed_password = generate_password_hash(password)
            new_user = User(username=username, password=hashed_password)
            db.session.add(new_user)
            db.session.commit()
            flash('Registration successful! You can now log in.', 'success')
            return redirect(url_for('login'))
    return render_template('register.html')

# Route for the dice rolling page
@app.route('/dice', methods=['GET', 'POST'])
def dice():
    if 'user_id' not in session:
        flash('You must be logged in to roll the dice.', 'danger')
        return redirect(url_for('login'))

    if request.method == 'POST':
        diceType = request.form['diceType']
        user_id = session['user_id']
        roll = random.randint(1, int(diceType))
        new_roll = DiceRoll(user_id=user_id, roll=roll, diceType=int(diceType)
        db.session.add(new_roll)
        db.session.commit()
        flash(f'You rolled a {roll}!', 'success')

    rolls = DiceRoll.query.filter_by(user_id=session['user_id']).order_by(DiceRoll.timestamp.desc()).all()
    return render_template('dice.html', rolls=rolls, username=session['username'])

# Route for logging out
@app.route('/logout')
def logout():
    session.clear()
    flash('You have been logged out.', 'info')
    return redirect(url_for('home'))

if __name__ == '__main__':
    app.run(debug=True, port=1000)