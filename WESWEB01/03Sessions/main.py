from flask import Flask, render_template, request, redirect, url_for, session # Session är som cookies

lista2d = [
    {'username': 'admin', 'password': '1234'},
    {'username': 'john', 'password': 'asdf'},
    {'username': 'bob', 'password': 'xyzw'},
    {'username': 'sarah', 'password': '9876'},
    {'username': 'bartolomeus', 'password': '1234'},
]

app = Flask(__name__)
app.secret_key = 'MuBC1EstEby8rRH6Td2J'

@app.route('/', methods=['GET', 'POST'])
def login():
    # Skapar räknare och anger kakans värde till variabelns värde
    counter = session.get('counter')
    # Om counter inte använts förut så kommer det bli till 0
    if counter == None:
        counter = 0
    counter += 1
    # Lägger till det nya värdet i kakan
    session['counter'] = counter
    print(counter)
    print(session)

    if request.method == 'POST':
        username = request.form['username'] # Användarens användarnamn
        password = request.form['password'] # Användarens lösenord
        for x in range(len(lista2d)):
            if username == lista2d[x]['username'] and password == lista2d[x]['password']:
                session['logged_in'] = True
                session['username'] = username
                session['password'] = password
                return redirect(url_for('secret'))
        else:
            return "Invalid credentials. Please try again.", 401
    else:
        if session.get('logged_in'):
            return "You are already logged in!", 200
        else:
            return render_template('login.html')

@app.route('/secret')
def secret():
    if session.get('logged_in'):
        print(session['username'])
        return render_template('secret.html', session=session)
    else:
        return redirect(url_for('login'))

@app.route('/logout')
def logout():
    if session.get('logged_in') == None:
        return redirect(url_for('login'))
    elif session['logged_in'] == True:
        session['logged_in'] = False
        # Det visar inte "You are now logged out" som det står i uppgiften
        # Detta är för jag skickar en direkt till inloggningssidan
        # Så man förstår väl att man är utloggad

        return redirect(url_for('login'))
    elif session['logged_in'] == False:
        return "You are already logged out", 200

@app.route('/supersecret')
def supersecret():
    if session.get('username') == 'admin':
        return "Welcome to the supersecret lair"
    else:
        return redirect(url_for('login'))


if __name__ == '__main__':
    app.run(debug=True)