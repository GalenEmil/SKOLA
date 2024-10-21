from flask import Flask, render_template, request, request, redirect, url_for, session
import random
import webbrowser
import time

counter = 0

def start_countdown(seconds_countdown=3):
    while seconds_countdown > 0:
        print(f"\rNästa inloggning om {seconds_countdown} sekunder...", end="")
        time.sleep(1)
        seconds_countdown -= 1

app = Flask(__name__)

@app.route("/")
def start():
    return render_template("start.html")

@app.route("/grind")
def grind():
    global counter
    for _ in range(0, 1000):
        webbrowser.open('https://matematik.nokportalen.se/5129/elev/oversikt')  # Go to example.com
        counter += 1
        print(f"Antal inloggningar denna grind session: {counter}")
        start_countdown(1830)
    return render_template("grind.html")

# För att kunna köra i visual studio code
if __name__ == '__main__':
    app.run(host = '0.0.0.0', debug=True, port=9000)