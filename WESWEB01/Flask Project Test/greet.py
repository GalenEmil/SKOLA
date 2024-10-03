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
# Slå tärning med GET och POST
@app.route('/dice', methods=['GET', 'POST'])
def dice():
    global counter
    if request.method == 'POST':
        min = int(request.form['min'])
        max = int(request.form['max'])
        counter += 1
        if min > max:
            return render_template('diceResult.html', counter=counter)
        else:
            result = random.randint(min, max)
            return render_template('diceResult.html', result=result, counter=counter)
        #f'<p>You rolled: {random.randint(min, max)}</p><p> Die has been rolled: {counter}</p>'
    else:
        return render_template('dice.html')
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
        num1 = float(request.form['number1'])
        num2 = float(request.form['number1'])
        result = num1 + num2
        return render_template('addResult.html', result=result)
    else:
        return render_template('add.html')
# PassGenerator
@app.route('/passGenerator', methods=['GET', 'POST'])
def passGenerator():
    if request.method == 'POST':
        alfabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZÅÄÖ"
        lösenord = ""
        bokstäver = int(request.form['bokstäver'])
        siffror = int(request.form['siffror'])
        for x in range(0, siffror):
            lösenord += str(random.randint(0, 9))
        for x in range(0, bokstäver):
            bokstav = alfabet[random.randint(0, (len(alfabet)-1))]
            lösenord += bokstav
        
        result = lösenord
        return render_template('passGeneratorResult.html', result=result)
    else:
        return render_template('passGenerator.html')
if __name__ == '__main__':
    app.run(host = '0.0.0.0', debug=True, port=9000)