from flask import Flask, render_template, request
import random

app = Flask(__name__)

@app.route("/")
def hello_world():
    return "<p>Hello, World!</p>"

@app.route("/greet/")
def greet_general():
    return render_template('greet.html')

@app.route("/greet/<name>")
def greet_person(name):
    return render_template('greet.html', name=name)

@app.route("/admin")
def admin():
    return render_template('greet.html', name="Admin")

@app.route("/dice")
def dice():
    return f"<p>You rolled: {random.randrange(1, 7)}</p>"

@app.route('/age', methods=['GET', 'POST'])
def calculate():
    if request.method == 'POST':
        age = float(request.form['age'])
        result = age + 1
        return render_template('ageResult.html', result=result)
    else:
        return render_template('age.html')

if __name__ =='__main__':  
    app.run(debug = True)