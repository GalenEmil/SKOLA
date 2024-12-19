from flask import Flask, render_template, request, redirect, url_for, session # Session är som cookies

app = Flask(__name__)
app.secret_key = 'MuBC1EstEby8rRH6Td2J'

# Standardrutt, Home
@app.route('/')
def home():
    return render_template('home.html')

# About rutt
@app.route('/about')
def about():
    return render_template('about.html')

# About rutt
@app.route('/contact')
def contact():
    return render_template('contact.html')

# About rutt
@app.route('/portfolio')
def portfolio():
    return render_template('portfolio.html')

@app.route('/portfolio/example1')
def example1():
    return render_template('example1.html')

@app.route('/portfolio/example2')
def example2():
    return render_template('example2.html')

if __name__ == '__main__':
    app.run(debug=True, port=9000)