# Lagra speldata i lexikon
# Lista/databas
goodStuff = []

# Alla dic med items
item1 = {
    "namn": "Järnsvärd",
    "kategori": "Vapen",
    "healing": 0,
    "skada": 20,
    "skydd": 0,
    "special": "Ingen",
}
item2 = {
    "namn":"Hälsobrygd",
    "kategori":"Brygd",
    "healing":30,
    "skada": 0,
    "skydd": 0,
    "special": "Ingen",
}
item3 = {
    "namn":"Reflektivt Halsband",
    "kategori":"Försvar",
    "healing": 0,
    "skada": 0,
    "skydd": 2,
    "special": "Diamantasering",
}
item4 = {
    "namn":"Hjälm",
    "kategori":"Försvar",
    "healing": 0,
    "skada": 0,
    "skydd":5,
    "special": "Ingen",
}
item5 = {
    "namn":"Järnbyxor",
    "kategori": "Försvar",
    "healing": 0,
    "skada": 0,
    "skydd": 24,
    "special": "Ingen",
}
item6 = {
    "namn":"Odins Läderskärp",
    "kategori":"Försvar",
    "healing": 0,
    "skada": 0,
    "skydd": 999,
    "special":"Förgiftning och Yrsel",
}
# Lägg till alla dic i listan
goodStuff.append(item1)
goodStuff.append(item2)
goodStuff.append(item3)
goodStuff.append(item4)
goodStuff.append(item5)
goodStuff.append(item6)

# Funktion för att skriva ut attribut för varje item
def printItem(item):
    print("Namn:", item["namn"])
    print("Kategori:", item["kategori"])
    print("skada:", item["skada"])
    print("Healing:", item["healing"])
    print("Skydd:", item["skydd"])
    print("Special:", item["special"])
    print("")
    print("")

# Skriv ut alla items
#for dic in goodStuff:
#    printItem(dic)

# Skriv ut bara odins läderskärp
printItem(goodStuff[5])

# Skriv ut alla items som har både försvar och en special
for dic in goodStuff:
    if dic["kategori"] == "Försvar" and dic["special"] != "Ingen":
        print("Item som skyddar mot effekter:", dic["namn"])
