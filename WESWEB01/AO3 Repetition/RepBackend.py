import sqlite3
from datetime import datetime
from flask import Flask, request, g, abort
from flask_restful import Resource, Api

DB_PATH = "store.db"


# ──────────────────────────────
#  DB helpers
# ──────────────────────────────
def get_db():
    if "db" not in g:
        g.db = sqlite3.connect(DB_PATH)
        g.db.row_factory = sqlite3.Row
    return g.db


def close_db(_=None):
    db = g.pop("db", None)
    if db is not None:
        db.close()


def init_db():
    db = sqlite3.connect(DB_PATH)
    cur = db.cursor()
    # Produkt listan
    cur.execute(
        """CREATE TABLE IF NOT EXISTS products(
            id       INTEGER PRIMARY KEY AUTOINCREMENT,
            name     TEXT NOT NULL,
            price    REAL NOT NULL,
            category TEXT NOT NULL)"""
    )
    # Users
    cur.execute(
        """CREATE TABLE IF NOT EXISTS users(
            id       INTEGER PRIMARY KEY AUTOINCREMENT,
            email    TEXT NOT NULL UNIQUE,
            password TEXT NOT NULL)"""
    )
    # Purchases
    cur.execute(
        """CREATE TABLE IF NOT EXISTS purchases(
            id         INTEGER PRIMARY KEY AUTOINCREMENT,
            user_email TEXT NOT NULL,
            item_name  TEXT NOT NULL,
            date       TEXT NOT NULL)"""
    )
    db.commit()
    db.close()


# ──────────────────────────────
#  Resources
# ──────────────────────────────
class ProductList(Resource):
    def get(self):
        cur = get_db().execute("SELECT * FROM products")
        return [dict(r) for r in cur.fetchall()], 200

    def post(self):
        data = request.get_json() or {}
        if not all(k in data for k in ("name", "price", "category")):
            abort(400)
        get_db().execute(
            "INSERT INTO products(name,price,category) VALUES (?,?,?)",
            (data["name"], data["price"], data["category"]),
        )
        get_db().commit()
        return {"message": "created"}, 201


class Product(Resource):
    def get(self, id):
        cur = get_db().execute("SELECT * FROM products WHERE id=?", (id,))
        row = cur.fetchone()
        if row:
            return dict(row), 200
        abort(404)

    def put(self, id):
        data = request.get_json() or {}
        get_db().execute(
            "UPDATE products SET name=?, price=?, category=? WHERE id=?",
            (data.get("name"), data.get("price"), data.get("category"), id),
        )
        get_db().commit()
        return {"message": "updated"}, 200

    def delete(self, id):
        get_db().execute("DELETE FROM products WHERE id=?", (id,))
        get_db().commit()
        return {"message": "deleted"}, 200


class UserList(Resource):
    def get(self):
        cur = get_db().execute("SELECT id,email,password FROM users")
        return [dict(r) for r in cur.fetchall()], 200

    def post(self):
        data = request.get_json() or {}
        if not all(k in data for k in ("email", "password")):
            abort(400)
        try:
            get_db().execute(
                "INSERT INTO users(email,password) VALUES (?,?)",
                (data["email"], data["password"]),
            )
            get_db().commit()
            return {"message": "created"}, 201
        except sqlite3.IntegrityError:
            abort(409)


class User(Resource):
    def get(self, id):
        cur = get_db().execute("SELECT id,email,password FROM users WHERE id=?", (id,))
        row = cur.fetchone()
        if row:
            return dict(row), 200
        abort(404)

    def put(self, id):
        data = request.get_json() or {}
        get_db().execute(
            "UPDATE users SET email=?, password=? WHERE id=?",
            (data.get("email"), data.get("password"), id),
        )
        get_db().commit()
        return {"message": "updated"}, 200

    def delete(self, id):
        get_db().execute("DELETE FROM users WHERE id=?", (id,))
        get_db().commit()
        return {"message": "deleted"}, 200


class PurchaseList(Resource):
    def get(self):
        cur = get_db().execute("SELECT * FROM purchases")
        return [dict(r) for r in cur.fetchall()], 200

    def post(self):
        data = request.get_json() or {}
        if not all(k in data for k in ("user_email", "item_name")):
            abort(400)
        date = data.get("date") or datetime.utcnow().isoformat()
        get_db().execute(
            "INSERT INTO purchases(user_email,item_name,date) VALUES (?,?,?)",
            (data["user_email"], data["item_name"], date),
        )
        get_db().commit()
        return {"message": "created"}, 201


class Purchase(Resource):
    def get(self, id):
        cur = get_db().execute("SELECT * FROM purchases WHERE id=?", (id,))
        row = cur.fetchone()
        if row:
            return dict(row), 200
        abort(404)

    def put(self, id):
        data = request.get_json() or {}
        get_db().execute(
            "UPDATE purchases SET user_email=?, item_name=?, date=? WHERE id=?",
            (
                data.get("user_email"),
                data.get("item_name"),
                data.get("date"),
                id,
            ),
        )
        get_db().commit()
        return {"message": "updated"}, 200

    def delete(self, id):
        get_db().execute("DELETE FROM purchases WHERE id=?", (id,))
        get_db().commit()
        return {"message": "deleted"}, 200


class Search(Resource):
    """GET /search?q=<term>"""

    def get(self):
        q = request.args.get("q", "")
        sql = "SELECT * FROM products WHERE name LIKE ?", (f'%{q}%',)
        cur = get_db().execute(sql)
        return [dict(r) for r in cur.fetchall()], 200


# ──────────────────────────────
#  Skapa app-objekt
# ──────────────────────────────
def create_app():
    init_db()
    app = Flask(__name__)
    api = Api(app)

    api.add_resource(ProductList, "/products")
    api.add_resource(Product, "/products/<int:id>")
    api.add_resource(UserList, "/users")
    api.add_resource(User, "/users/<int:id>")
    api.add_resource(PurchaseList, "/purchases")
    api.add_resource(Purchase, "/purchases/<int:id>")
    api.add_resource(Search, "/search")

    app.teardown_appcontext(close_db)
    return app


create_app().run(debug=True, port=5000)
