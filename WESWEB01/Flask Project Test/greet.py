# Import av allt
from flask import Flask, render_template, request
from markupsafe import escape
import random


app = Flask(__name__)

counter = 0

# Standard rutt
@app.route('/')
def blabla():
    return '<p>blabla</p>   <a href="/dice"> Roll a dice</a>   <a href="/hej">Hälsningsfras </a>'

# Hälsning med namn på Jacobs sätt med jinja mallar
@app.route("/hej/<name>")
def hej(name):
    return render_template("hej.html", name=name)
# Hälsning fast utan namn
@app.route("/hej")
def hej_utan_namn():
    return render_template("hej.html")
# Hälsning med namn fast med escape
@app.route('/greet/<name>')
def greet(name):
    return f'<p>Hej {escape(name)}</p>'
# Slå tärning
@app.route('/dice')
def dice():
    global counter
    counter += 1
    return f'<p>You rolled: {random.randint(1, 6)}</p><p> Die has been rolled: {counter}</p>'
# Ålders kalkylator
@app.route('/age', methods=['GET', 'POST'])
def calculate():
    if request.method == 'POST':
        age = float(request.form['age'])
        result = age + 1
        return render_template('ageResult.html', result=result)
    else:
        return render_template('age.html')
# Lägg ihop två nummer
@app.route('/add', methods=['GET', 'POST'])
def add():
    if request.method == 'POST':
        sum = float(request.form[''])
        sum = sum + 1
        return render_template('addResult.html', sum=sum)
    else:
        return render_template('add.html')


if __name__ == '__main__':
    app.run(host = '0.0.0.0', debug=True, port=9000)