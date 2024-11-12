import random
# Main loop
# Räknar vinnserie
winTieLoss = {
    "vinst:": 0,
    "förlust:": 0,
    "oavgjort:": 0
}
while True:
    # Spelarens val
    spelarVal = input("Välj sten, sax eller påse: ")
    if spelarVal != "sten" and spelarVal != "sax" and spelarVal != "påse":
        print("Felaktigt val, avslutar programmet")

    # Datorns random val
    datorVal = random.randint(1, 3)
    result = ""
    if datorVal == 1:
        datorVal = "sten"
    elif datorVal == 2:
        datorVal = "sax"
    else:
        datorVal = "påse"

    print(f"Du valde {spelarVal} och datorn valde {datorVal}")

    # Kollar vem som vinner
    if spelarVal == "sten" and datorVal == "sten":
        result = "oavgjort"
    elif spelarVal == "sax" and datorVal == "sax":
        result = "oavgjort"
    elif spelarVal == "påse" and datorVal == "påse":
        result = "oavgjort"

    if spelarVal == "sten" and datorVal == "påse":
        result = "Datorn vinner"
    elif spelarVal == "sax" and datorVal == "sten":
        result = "Datorn vinner"
    elif spelarVal == "påse" and datorVal == "sax":
        result = "Datorn vinner"
    elif spelarVal == "sten" and datorVal == "sax":
        result = "Du vinner"
    elif spelarVal == "sax" and datorVal == "påse":
        result = "Du vinner"
    elif spelarVal == "påse" and datorVal == "sten":
        result = "Du vinner"

    # Skriver ut resultatet

    print(result)

    # Lägger till i vinnserie
    if result == "Du vinner":
        winTieLoss["vinst:"] += 1
    elif result == "Datorn vinner":
        winTieLoss["förlust:"] += 1
    elif result == "oavgjort":
        winTieLoss["oavgjort:"] += 1

    # Skriver ut vinnserie
    for x, y in winTieLoss.items():
        print(x, y)

    # Frågar om man vill köra igen
    igen = input("Vill du köra igen? (y/n): ")
    if igen == "n":
        break
    elif igen == "y":
        continue
    else:
        print("Felaktigt val, avslutar programmet")
        break