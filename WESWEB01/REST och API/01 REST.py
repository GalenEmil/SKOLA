import os
import sqlite3
from flask import Flask, request, jsonify, g, render_template, redirect, url_for
app = Flask(__name__)

DATABASE = 'items.db'

def get_db():
    """
    Establish a database connection for the current application context.
    """
    db = getattr(g, '_database', None)
    if db is None:
        db = sqlite3.connect(DATABASE)
        db.row_factory = sqlite3.Row  # Enables name-based access to columns
        g._database = db
    return db

@app.teardown_appcontext
def close_connection(exception):
    """
    Close the database connection at the end of the request.
    """
    db = getattr(g, '_database', None)
    if db is not None:
        db.close()

def find_item_by_id(item_id):
    db = get_db()
    cursor = db.execute('SELECT * FROM items WHERE id=?', (item_id,))
    item = cursor.fetchall()
    # Kolla om item finns
    if item:
        return item
    else:
        return None

@app.route('/ping', methods=['GET'])
def ping():
    return jsonify({"message": "pong"})

@app.route('/items', methods=['GET'])
def get_items():
    db = get_db()
    cursor = db.execute('SELECT * FROM items')
    items = cursor.fetchall()
    return jsonify(items)

@app.route('/items/<int:item_id>', methods=['GET'])
def get_item(item_id):
    item = find_item_by_id(item_id)
    if item:
        return jsonify(item)
    return jsonify({"error": "Item not found"}), 404

@app.route('/items', methods=['POST'])
def create_item():
    data = request.get_json()
    if not data or "name" not in data or "price" not in data:
        return jsonify({"error": "Invalid input"}), 400
    
    db = get_db()
    cursor = db.execute('')
    temp_id = cursor.fetchone()
    cursor = db.execute('INSERT INTO items (id, name, price) VALUES (?, ?, ?)', (id, data["name"], data["price"]))
    new_item = {
        "id": len(items) + 1,
        "name": data["name"],
        "price": data["price"]
    }
    items.append(new_item)
    return jsonify(new_item), 201

@app.route('/echo', methods=['POST'])
def echo():
    data = request.get_json()
    return jsonify({"received": data})

@app.route('/hello', methods=['GET'])
def hello():
    return jsonify({"message": "Hello World"})

@app.route('/uppercase', methods=['POST'])
def uppercase():
    data = request.get_json()
    text = str(data["text"]).upper()
    return jsonify({"text": text})

if __name__ == '__main__':
    app.run(debug=True, port=9000)
