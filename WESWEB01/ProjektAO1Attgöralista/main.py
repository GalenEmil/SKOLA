from flask import Flask, render_template, request, redirect, url_for, session # Session är som cookies
import csv
import os
toDoList = []

listaMedLex = []

toDoList=[]

os.chdir(r'C:\Users\emil.bonevnilsson\Github\SKOLA\WESWEB01\ProjektAO1Attgöralista')

# Funktion som ska läsa av csv filen och lägga in det i ett lexikon
def readCSV(csv_file):
    global listaMedLex
    tempCounter = 0
    # Öppna filen
    with open(csv_file, newline='') as csvfile:
        # Läs av filen
        reader = csv.reader(csvfile)
        # Gå igenom varje rad av filen och lägg till det i listaMedLex
        for row in reader:
            #print(type(row)) # Det är en lista
            listaMedLex.append({})
            listaMedLex[tempCounter]['mail'] = row[0]
            listaMedLex[tempCounter]['password'] = row[1]
            listaMedLex[tempCounter]['name'] = row[2]
            tempCounter += 1

def writeCSV(csv_file):
    global listaMedLex
    with open(csv_file, 'w', newline='') as csvfile:
        spamwriter = csv.writer(csvfile, quoting=csv.QUOTE_MINIMAL)
        for x in listaMedLex:
            spamwriter.writerow([x['mail'], x['password'], x['name']])

fil = 'users.csv'

# Skriver in från csv till lexikonet
readCSV(fil)
# Skriver in från lexikonet till csv
writeCSV(fil)

app = Flask(__name__)
app.secret_key = 'MuBC1EstEby8rRH6Td2J'

# Standardrutt, Home
@app.route('/', methods=['GET', 'POST'])
def home():
    if session.get('toDoList') == None:
        session['toDoList'] = toDoList
    toDoList = session['toDoList']
    if request.method == 'POST':
        if session.get('logged_in'):
            # Lägger till en ny sak och beskrivning i listan
            toDoList.append({})
            item = request.form['item']
            desc = request.form['desc']
            toDoList[-1]['item'] = item
            toDoList[-1]['desc'] = desc
            session['toDoList'] = toDoList
            return render_template('home.html', session=session, toDoList=toDoList)
        else:
            return redirect(url_for('register'))
    else:
        if session.get('logged_in'):
            return render_template('home.html', session=session, toDoList=toDoList)
        else:
            return render_template('register.html')

# Login rutt
@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        mail = request.form['mail'] # Användarens E-mail
        password = request.form['password'] # Användarens lösenord
        for x in listaMedLex:
            if mail == x['mail'] and password == x['password']:
                session['logged_in'] = True
                session['mail'] = mail
                session['password'] = password
                session['name'] = x['name']
                return redirect('/')
        else:
            return "<p>Invalid credentials. Please try again.</p>", 401
    else:
        if session.get('logged_in'):
            return "<p>You are already logged in!</p>", 200
        else:
            return render_template('login.html')

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

# About rutt
@app.route('/about')
def about():
    return render_template('about.html')

# Register rutt
@app.route('/register', methods=['GET', 'POST'])
def register():
    global listaMedLex
    if request.method == 'POST':
        mail = request.form['mail'] # Användarens E-mail
        password = request.form['password'] # Användarens lösenord
        name = request.form['name'] # Användarens namn
    # Om någon av värdena är toma så kommer det ett felmed
        if len(name) <= 0 or len(password) <= 0 or len(mail) <= 0:
            # Lägg in användarens uppgifter i lexikonet
            listaMedLex.append({})
            listaMedLex[-1]['mail'] = mail
            listaMedLex[-1]['password'] = password
            listaMedLex[-1]['name'] = mail
            # Lägg in användarens uppgifter i csv filen
            writeCSV(fil)
            session['logged_in'] = True
            session['mail'] = mail
            session['password'] = password
            session['name'] = name
            return redirect('/')
        else:
            return "<p>Invalid credentials. Please try again.</p>", 401
    else:
        if session.get('logged_in'):
            return "<p>You are already logged in!</p>", 200
        else:
            return render_template('register.html')


if __name__ == '__main__':
    app.run(debug=True)