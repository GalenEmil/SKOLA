from flask import Flask, request, jsonify

app = Flask(__name__)

# Sample data store
items = [
    {"id": 1, "name": "Item 1", "price": 10.99},
    {"id": 2, "name": "Item 2", "price": 15.49}
]

def find_item_by_id(item_id):
    for item in items:
        if item["id"] == item_id:
            return item
    return None

@app.route('/ping', methods=['GET'])
def ping():
    return jsonify({"message": "pong"})

@app.route('/items', methods=['GET'])
def get_items():
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
