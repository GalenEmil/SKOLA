from flask import Flask, render_template, request, redirect, url_for, session # Session är som cookies
import csv
import os
"""
lista2d = [
    {'username': 'admin', 'password': '1234'},
    {'username': 'john', 'password': 'asdf'},
    {'username': 'bob', 'password': 'xyzw'},
    {'username': 'sarah', 'password': '9876'},
    {'username': 'bartolomeus', 'password': '1234'},
]
#            print(row['username'], row['password'])
"""

os.chdir(r'C:\Users\emil.bonevnilsson\Github\SKOLA\WESWEB01\03Sessions')
fil = 'users.csv'
# Lista som ska imitera den ovan
listaMedLex = []
# Funktion som ska läsa av csv filen och lägga in det i ett lexikon
def readCSV(csv_file):
    global listaMedLex
    tempCounter = 0
    # Öppna filen
    with open(csv_file, newline='') as csvfile:
        # Läs av filen
        reader = csv.reader(csvfile)
        print(reader)
        # Gå igenom varje rad av filen och lägg till det i listaMedLex
        for row in reader:
            #print(type(row)) Det är en lista
            # Jag ville ta len(reader) men eftersom det inte går så tog jag bara en siffra, 10
            listaMedLex.append({})
            listaMedLex[tempCounter]['username'] = row[0]
            listaMedLex[tempCounter]['password'] = row[1]
            tempCounter += 1
        print(listaMedLex)

readCSV(fil)

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
        for x in range(len(listaMedLex)):
            if username == listaMedLex[x]['username'] and password == listaMedLex[x]['password']:
                session['logged_in'] = True
                session['username'] = username
                session['password'] = password
                return redirect(url_for('secret'))
        else:
            return "<p>Invalid credentials. Please try again.</p>", 401
    else:
        if session.get('logged_in'):
            return "<p>You are already logged in!</p>", 200
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
        return "<p>You are already logged out</p>", 200

@app.route('/supersecret')
def supersecret():
    if session.get('username') == 'admin':
        return "<p>Welcome to the super secret page that only admins can see.</p>"

    elif session.get('logged_in') == True:
        return redirect(url_for('secret'))
    else:
        return redirect(url_for('login'))


if __name__ == '__main__':
    app.run(debug=True)