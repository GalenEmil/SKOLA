from flask import Flask, request, jsonify
import sqlite3
import os

app = Flask(__name__)

DATABASE = 'users.db'

def init_db():
    if not os.path.exists(DATABASE):
        conn = sqlite3.connect(DATABASE)
        conn.execute('''CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            email TEXT NOT NULL,
            password TEXT NOT NULL
        )''')
        conn.commit()
        conn.close()

@app.route('/user/<user_id>', methods=['GET'])
def get_user_by_id(user_id):
    conn = sqlite3.connect(DATABASE)
    cursor = conn.cursor()
    cursor.execute("SELECT id, email FROM users WHERE id = ?", (user_id,))
    result = cursor.fetchone()
    conn.close()

    if result:
        user_data = {
            'id': result[0],
            'email': result[1]
        }
        return jsonify(user_data), 200
    else:
        return jsonify({'code': 'User not found'}), 404

@app.route('/login', methods=['POST'])
def login():
    data = request.get_json()
    
    email = data.get('email', '')
    password = data.get('password', '')
    
    conn = sqlite3.connect(DATABASE)
    cursor = conn.cursor()
    cursor.execute("SELECT * FROM users WHERE email = ? AND PASSWORD = ?", (email, password,))
    result = cursor.fetchone()
    conn.close()

    if not result:
        return jsonify({'code': 'No such user, or wrong password'}), 401
    else:
        return jsonify({'code': f'Successfully logged in as {result[1]}!'}), 200

@app.route('/update_password', methods=['POST'])
def update_password():
    data = request.get_json()
    
    user_id = data.get('user_id', '')
    new_password = data.get('new_password', '')

    conn = sqlite3.connect(DATABASE)
    cursor = conn.cursor()
    cursor.execute("UPDATE users SET password = ? WHERE id = ?", (new_password, user_id,))
    conn.commit()
    conn.close()

    return jsonify({'code': 'Password updated (insecurely)'}), 200

@app.route('/userinfo', methods=['GET'])
def user_info():
    field = request.args.get('field', 'id')
    email = request.args.get('email', '')
    query = f"SELECT {field} FROM users WHERE email = ?"
    # Gör så att field inte kan vara Password
    # Då kan man inte hämta det så lätt
    if field == "password":
        return jsonify({'code': 'Not allowed to request passwords'}), 401
    
    conn = sqlite3.connect(DATABASE)
    cursor = conn.cursor()
    cursor.execute(query, (email,))
    results = cursor.fetchone()
    conn.close()

    return jsonify(results), 200

if __name__ == '__main__':
    init_db()
    app.run(debug=True, port=9000)