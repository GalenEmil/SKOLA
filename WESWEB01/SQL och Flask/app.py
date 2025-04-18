import os
import sqlite3
from flask import Flask, request, render_template, g, redirect, url_for

app = Flask(__name__)

DATABASE = 'testdata.db'

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

@app.route('/')
def index():
    """
    Show a list of all products in the store.
    """
    db = get_db()
    cursor = db.execute('SELECT * FROM products')
    products = cursor.fetchall()

    cursor = db.execute('SELECT * FROM users')
    users = cursor.fetchall()
    return render_template('index.html', products=products, users=users)

@app.route('/user/<int:user_id>')
def user(user_id):
    # Öppnar databas
    db = get_db()
    # Hämtar purchases från databas
    cursor = db.execute('SELECT * FROM purchases')
    purchases = cursor.fetchall()
    # Hämtar users från databas
    cursor = db.execute('SELECT * FROM users WHERE id=?', (user_id,))
    user = cursor.fetchone()
    # Hämtar products från databas
    cursor = db.execute('SELECT * FROM products')
    products = cursor.fetchall()
    # Hämtar summan
    cursor = db.execute('SELECT sum(price) FROM(SELECT * FROM purchases JOIN products ON purchases.product_id = products.id) WHERE user_id = ?;', (user_id,))
    summa = cursor.fetchone()
    return render_template('user.html', purchases=purchases, user=user, products=products, summa=summa)

@app.route('/product/<int:product_id>', methods=['GET', 'POST'])
def product_details(product_id):
    """
    Show details for a specific product using a URL parameter (product_id).
    """
    db = get_db()
    # Hämta recensionerna
    cursor = db.execute('SELECT * FROM products WHERE id=?', (product_id,))
    product = cursor.fetchone()
    users = db.execute('SELECT * FROM users').fetchall()
    cursor = db.execute('SELECT * FROM reviews WHERE product_id = ?', (product_id,))
    reviews = cursor.fetchall()
    # Måste köras innan listan blir sorterad och slicead
    avarage = 0
    sum = 0
    count = 0
    for review in reviews:
        if review['product_id'] == product['id']:
            sum += review['rating']
            count += 1
    if count <= 0:
        pass
    else:
        avarage = sum/count

    if request.method == 'POST':
        action = request.form.get('action')  # Kolla vilken knapp som klickades
        if action == 'post_review':
            text = request.form['text']
            user_id = request.form['user_id']
            date = request.form['date']
            rating = request.form['rating']
            db.execute('INSERT INTO reviews (user_id, product_id, date, text, rating) VALUES (?, ?, ?, ?, ?)',
            (user_id, product_id, date, text, rating))
            db.commit()
        elif action == 'sort_reviews':
            # Hantera sortering
            sort_option = request.form['sorting']  # T.ex. "Highest Rating"
            if sort_option == "high":
                reviews = sorted(reviews, key=lambda r: r['rating'], reverse=True)
            elif sort_option == "low":
                reviews = sorted(reviews, key=lambda r: r['rating'])
            elif sort_option == "new":
                reviews = sorted(reviews, key=lambda r: r['date'], reverse=True)
            elif sort_option == "old":
                reviews = sorted(reviews, key=lambda r: r['date'])

            # Visa bara de 10 första efter sortering
            reviews = reviews[:10]

    return render_template('product_details.html', product=product, users=users, reviews=reviews, avarage=avarage)

@app.route('/add_user', methods=['GET', 'POST'])
def add_user():
    """
    Handle both GET (display form) and POST (form submission) for adding a new user.
    """
    if request.method == 'POST':
        username = request.form['username']
        email = request.form['email']
        db = get_db()
        db.execute('INSERT INTO users (username, email) VALUES (?, ?)', (username, email))
        db.commit()
        return redirect(url_for('index'))
    return render_template('add_user.html')

@app.route('/purchase', methods=['GET', 'POST'])
def purchase():
    """
    Handle both GET (display form) and POST (form submission) for making a purchase.
    """
    db = get_db()
    if request.method == 'POST':
        user_id = request.form['user_id']
        product_id = request.form['product_id']
        date = request.form['date']
        db.execute('INSERT INTO purchases (user_id, product_id, date) VALUES (?, ?, ?)',
        (user_id, product_id, date))
        db.commit()
        return redirect(url_for('index'))

    # If GET, show a form with a list of users and products
    users = db.execute('SELECT * FROM users').fetchall()
    products = db.execute('SELECT * FROM products').fetchall()
    return render_template('purchase_form.html', users=users, products=products)

def init_db():
    """
    Create tables in the database if they do not exist yet.
    """
    with sqlite3.connect(DATABASE) as conn:
        cur = conn.cursor()
        # Create the products table
        cur.execute("""
        CREATE TABLE IF NOT EXISTS products (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            category TEXT NOT NULL CHECK (category IN ('Grocery', 'Appliance', 'Clothing')),
            price REAL NOT NULL CHECK (price >= 0)
        );
        """)
        # Create the users table
        cur.execute("""
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            username TEXT NOT NULL UNIQUE,
            email TEXT NOT NULL UNIQUE
        );
        """)
        # Create the purchases table
        cur.execute("""
        CREATE TABLE IF NOT EXISTS purchases (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            user_id INTEGER NOT NULL,
            product_id INTEGER NOT NULL,
            date DATE NOT NULL,
            FOREIGN KEY(user_id) REFERENCES users(id) ON DELETE CASCADE,
            FOREIGN KEY(product_id) REFERENCES products(id) ON DELETE CASCADE
        );
        """)
        # Create the reviews table
        cur.execute("""
        CREATE TABLE IF NOT EXISTS reviews (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            user_id INTEGER NOT NULL,
            product_id INTEGER NOT NULL,
            date DATE NOT NULL,
            text TEXT NOT NULL,
            FOREIGN KEY(user_id) REFERENCES users(id) ON DELETE CASCADE,
            FOREIGN KEY(product_id) REFERENCES product(id) ON DELETE CASCADE
        );
        """)

if __name__ == '__main__':
    # Initialize the database
    if not os.path.exists(DATABASE):
        init_db()

    # Start the Flask development server
    app.run(debug=True, port=9000)
