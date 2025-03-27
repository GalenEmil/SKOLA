from flask import Flask, jsonify
from flask_restful import Resource, Api, reqparse, abort
from flask_sqlalchemy import SQLAlchemy
from sqlalchemy.exc import SQLAlchemyError

app = Flask(__name__)

# Configure database (SQLite in-memory for demonstration)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///todo.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False

db = SQLAlchemy(app)
api = Api(app)

# ------------------------------------------------------------------------------
# Database Model
# ------------------------------------------------------------------------------
# Model för Task
class Task(db.Model):
    __tablename__ = 'tasks'
    id = db.Column(db.Integer, primary_key=True, autoincrement=True)
    title = db.Column(db.String(120), nullable=False)
    description = db.Column(db.String(250), nullable=True)
    done = db.Column(db.Boolean, default=False)

    def to_dict(self):
        return {
            'id': self.id,
            'title': self.title,
            'description': self.description,
            'done': self.done
        }
# Model för Label
class Label(db.Model):
    __tablename__ = 'labels'
    id = db.Column(db.Integer, primary_key=True, autoincrement=True)
    name = db.Column(db.String(120), nullable=False)
    color = db.Column(db.String(120), nullable=True)

    def to_dict(self):
        return {
            'id': self.id,
            'name': self.name,
            'color': self.color
        }

# ------------------------------------------------------------------------------
# Validation parsers
# ------------------------------------------------------------------------------
# Task parser
task_parser = reqparse.RequestParser()
task_parser.add_argument('title', type=str, required=True, help="Title cannot be blank!")
task_parser.add_argument('description', type=str, required=False, default="")
task_parser.add_argument('done', type=bool, required=False, default=False)
# Label parser
label_parser = reqparse.RequestParser()
label_parser.add_argument('name', type=str, required=True, help="Name cannot be blank!")
label_parser.add_argument('color', type=str, required=False, default="")

# ------------------------------------------------------------------------------
# Resource definitions
# ------------------------------------------------------------------------------
class TaskListResource(Resource):
    def get(self):
        """
        GET /todo/api/tasks
        Return a list of all tasks.
        """
        tasks = Task.query.all()
        return [task.to_dict() for task in tasks], 200

    def post(self):
        """
        POST /todo/api/tasks
        Create a new task.
        JSON body example:
        {
            "title": "Buy groceries",
            "description": "Milk, Bread, Eggs",
            "done": false
        }
        """
        args = task_parser.parse_args()
        new_task = Task(
            title=args['title'],
            description=args['description'],
            done=args['done']
        )
        try:
            db.session.add(new_task)
            db.session.commit()
        except SQLAlchemyError as e:
            db.session.rollback()
            abort(400, message=str(e))

        return new_task.to_dict(), 201


class TaskResource(Resource):
    def get(self, task_id):
        """
        GET /todo/api/tasks/<task_id>
        Retrieve a task by its ID.
        """
        task = Task.query.get(task_id)
        if not task:
            abort(404, message=f"Task with id={task_id} not found.")
        return task.to_dict(), 200

    def put(self, task_id):
        """
        PUT /todo/api/tasks/<task_id>
        Update an existing task.
        """
        task = Task.query.get(task_id)
        if not task:
            abort(404, message=f"Task with id={task_id} not found.")

        args = task_parser.parse_args()
        task.title = args['title']
        task.description = args['description']
        task.done = args['done']

        try:
            db.session.commit()
        except SQLAlchemyError as e:
            db.session.rollback()
            abort(400, message=str(e))

        return task.to_dict(), 200

    def delete(self, task_id):
        """
        DELETE /todo/api/tasks/<task_id>
        Delete a task by its ID.
        """
        task = Task.query.get(task_id)
        if not task:
            abort(404, message=f"Task with id={task_id} not found.")

        try:
            db.session.delete(task)
            db.session.commit()
        except SQLAlchemyError as e:
            db.session.rollback()
            abort(400, message=str(e))

        return {'message': 'Task deleted'}, 200

class LabelListResource(Resource):
    def get(self):
        """
        GET /todo/api/labels
        Ge tillbaka listan av alla labels
        """
        labels = Label.query.all()
        return [label.to_dict() for label in labels], 200

    def post(self):
        """
        POST /todo/api/labels
        Skapa en ny label med en POST request
        """
        args = label_parser.parse_args()
        new_label = Label(
            name=args['name'],
            color=args['color']
        )
        try:
            db.session.add(new_label)
            db.session.commit()
        except SQLAlchemyError as e:
            db.session.rollback()
            abort(400, message=str(e))

        return new_label.to_dict(), 201

class LabelResource(Resource):
    def get(self, label_id):
        """
        GET /todo/api/labels/<label_id>
        Hämta en label med dess ID
        """
        label = Label.query.get(label_id)
        if not label:
            abort(404, message=f"Labels with id={label_id} not found.")
        return label.to_dict(), 200

    def put(self, label_id):
        """
        PUT /todo/api/labels/<label_id>
        Uppdatera innehåll i en label utifrån dess ID
        """
        label = Label.query.get(label_id)
        if not label:
            abort(404, message=f"Labels with id={label_id} not found.")

        args = label_parser.parse_args()
        label.name = args['name']
        label.color = args['color']

        try:
            db.session.commit()
        except SQLAlchemyError as e:
            db.session.rollback()
            abort(400, message=str(e))

        return label.to_dict(), 200

    def delete(self, label_id):
        """
        DELETE /todo/api/labels/<label_id>
        Ta bort en label utifrån dess ID
        """
        label = Label.query.get(label_id)
        if not label:
            abort(404, message=f"Labels with id={label_id} not found.")

        try:
            db.session.delete(label)
            db.session.commit()
        except SQLAlchemyError as e:
            db.session.rollback()
            abort(400, message=str(e))

        return {'message': 'Label deleted'}, 200

# ------------------------------------------------------------------------------
# Routes registration
# ------------------------------------------------------------------------------
api.add_resource(TaskListResource, '/todo/api/tasks')
api.add_resource(TaskResource, '/todo/api/tasks/<int:task_id>')
api.add_resource(LabelListResource, '/todo/api/labels')
api.add_resource(LabelResource, '/todo/api/labels/<label_id>')
# ------------------------------------------------------------------------------
# Initialize the database
# ------------------------------------------------------------------------------
with app.app_context():
    db.create_all()

# ------------------------------------------------------------------------------
# Run the server
# ------------------------------------------------------------------------------
if __name__ == '__main__':
    app.run(debug=True, port=9000)