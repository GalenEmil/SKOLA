# Importera flask
from flask import Flask
# Importera random
import random

# Viktig klass i Flask
app = Flask(__name__)

# Rot rutten. Inget på slutet av webbsidans URL
# http://127.0.0.1:9000
@app.route("/")
def index():
    return '<p>Hello World!</p><a href="/dice">Roll a dice</a>'

# Här väljer vi /dice som rutt och skriver det i slutet av webbsidans URL
# http://127.0.0.1:9000/dice
# Denna URL är alltså bunden till funktionen roll_dice
@app.route("/dice")
def roll_dice():
    värde = random.randint(1, 6)
    return f"<p>You rolled: {värde}</p>"

# If-statement
# För att kunna köra i visual studio code
if __name__ == '__main__':
    app.run(host = '0.0.0.0', debug=True, port=9000)