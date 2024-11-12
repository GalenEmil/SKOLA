import random

# Funktion som genererar ett namn slumpmässigt.

def generateNameAndTitle():
    # Listor med en liten mix av namn
    förnamn = ["Donald", "Kamala", "Joe", "Stefan", "Bartalomeus", "Ulf"]
    efternamn = ["Trump", "Harris", "Biden", "Löfven", "Farnsworth", "Kristersson"]
    # Listor med en liten mix av titlar
    titlar = ["Korvätarn ", "Den korrupta ", "Presidenten av Amerikas förenta stater ", "Den orangehyade ",]
    namn = random.choice(titlar) + random.choice(förnamn) + " " + random.choice(efternamn)
    return namn

# Omvandla temperatur C till F
def omvandlingCToF(tempC):
    tempF = (tempC * 1.8) + 32
    print(tempC, "C =", tempF, "F")
    return 0

# Meters to feet funktion
def metersToFeet(meters):
    feet = meters * 3.28084
    feet = round(feet, 2)
    print(meters, "meters =", feet, "feet")
    return 0

# Kilograms to pounds funktion
def kilogramsToPounds(kg):
    lbs = kg * 2.20462
    lbs = round(lbs, 2)
    print(kg, "kilograms =", lbs, "pounds")
    return 0

# Funktion för att skapa lösenord
def createPassword(längd):
    alfabetet = "abcdefghijklmnopqrstuvwxyzåäö"
    nyttOrd = ""
    for x in range(längd):
        nyttOrd += random.choice(alfabetet)
    print("Lösenord:", nyttOrd)
    return 0

# Funktion för att räkna ut cirkelns area
def circleArea(radie):
    area = radie * radie * 3.14159
    area = round(area, 1)
    print ("Cirkelns area är:", area)
    return 0

# Funktion för att räkna ut hur många gånger ord upprepas(utmaning)
def frekvensAvOrd(text):
    # Skapar lista med alla listans ord
    listaMedOrd = text.split()
    # Skapar lexikon
    dic = {}
    # Loopar igenom listan och lägger till orden som nycklar i lexikonet med värdet 1 om ordet inte fanns innan
    # Om ordet fanns innan så adderas värdet 1
    for x in range(len(listaMedOrd)):
        if dic.get(listaMedOrd[x]) != None:
            dic[listaMedOrd[x]] += 1
        else:
            dic[listaMedOrd[x]] = 1
        
    # Printar ut
    for key in dic:
        print(str(key) + ": " + str(dic[key]))
    # Om man vill använda dictionariet till något annat
    return dic

# Funktion för att se vanligaste och ovanligaste orden i en mening(utmaning)
def jacob(text):
    # Dictionary/Lexikon
    dic = frekvensAvOrd(text)
    dicFlest = {}
    #nyssFlest = 0
    dicFärst = {}
    #nyssFärst = 3141592
    
    # Robin Metod. Fungerar
    """
    nyssFärst = min(dic.values())
    for x, y in dic.items():
        if y == nyssFärst:
            dicFärst[x] = y
    nyssFlest = max(dic.values())
    for x, y in dic.items():
        if y == nyssFlest:
            dicFlest[x] = y
    """
    # Emil Metod 1. Fungerar inte
    """
    for x in range(100):
        for key in dic:
            if dic[key] >= nyssFlest:
                nyssFlest = dic[key]
                dicFlest[key] = nyssFlest
            if dic[key] <= nyssFärst:
                nyssFärst = dic[key]
                dicFärst[key] = nyssFärst
    print(f"Mest vanliga - ({dicFlest})")
    print(f"Mest ovanliga - ({dicFärst})")
    """
    # Emil metod 2
    # Hittar största och minsta värdet
    Färst = min(dic.values())
    Flest = max(dic.values())
    # Loopar igenom lexikonet som har antalet ord
    # Lägger till de ord som det finns flest respektive färst av i sina lexikon
    for key, value in dic.items():
        if dic[key] == Flest:
            dicFlest[key] = dic[key]
        if dic[key] == Färst:
            dicFärst[key] = dic[key]
    # Skriv ut
    print(f"Vanligaste -", end=" ")
    for key, value in dicFlest.items():
        print(f"{key}({value})", end=" ")
    print("\n")
    print(f"Mest Ovanligt -", end=" ")
    for key, value in dicFärst.items():
        print(f"{key}({value})", end=" ")
    print("\n")
# Skriv ut
print("Din lärare:", generateNameAndTitle())
print("Din chef :", generateNameAndTitle())
print("Din bästa kompis:", generateNameAndTitle())
print("Din G:", generateNameAndTitle())
print("Din bortglömda vän:", generateNameAndTitle())
print("Din avlägsna släkting:", generateNameAndTitle())

omvandlingCToF(23.4)
omvandlingCToF(32.6)

metersToFeet(2.0)
metersToFeet(1.4)

kilogramsToPounds(42)
kilogramsToPounds(63)

createPassword(8)
createPassword(0)
createPassword(-1)
createPassword(100)

circleArea(8) # borde bli 201.1
circleArea(2) # borde bli 12.6
circleArea(6) # borde bli  113

frekvensAvOrd("green apples and green trees and green bananas")

jacob("green apples and green trees and green bananas")