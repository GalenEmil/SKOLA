from flask import Flask, render_template, request
import random

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/about')
def about():
    team_members = [
        {'name': 'Alice Smith', 'title': 'CEO', 'bio': 'Alice leads the company with a vision for growth.'},
        {'name': 'Bob Johnson', 'title': 'Innovation Coordinator', 'bio': 'Bob drives innovation across all departments.'},
        {'name': 'Carol Williams', 'title': 'Sales Coordinator', 'bio': 'Carol connects our solutions with customers.'},
        {'name': "Bartolomeus 'The guy' Roosevelt", 'title': "Supreme Overlord", 'bio': "Bartolomeus Works with basically everything"},
    ]
    return render_template('about.html', team_members=team_members)

@app.route('/advice', methods=['GET', 'POST'])
def advice():
    advice_list = [
        "Always keep learning.",
        "Stay positive and work hard.",
        "Embrace challenges as opportunities.",
        "Communicate clearly and effectively.",
        "Set realistic goals and achieve them."
    ]
    advice_text = ''
    if request.method == 'POST':
        advice_text = random.choice(advice_list)
    return render_template('advice.html', advice=advice_text)

@app.route('/products')
def products():
    products_list = [
        {'name': "Basic Toaster", 'bio': "You know what they say, all toasters toast toast.", 'price': 360},
        {'name': "Deluxe Vacuum Cleaner", 'bio': "The solution to all your cleaning problems", 'price': 1300},
        {'name': "Ultra Mega Vacuum Cleaner", 'bio': "Even more fantastic than the Deluxe vacuum", 'price': 2600},
        {'name': "Bartolomeus", 'bio': "Human Trafficking??!!", 'price': "INVALUABLE "},
    ]
    return render_template('products.html', products_list=products_list)
if __name__ == '__main__':
    app.run(debug=True, port=9000)
