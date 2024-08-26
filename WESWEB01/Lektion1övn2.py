import random

spelarVal = input("Välj sten, sax eller påse: ")

datorVal = random.randint(1, 3)

result = ""

if datorVal == 1:
    datorVal = "sten"
elif datorVal == 2:
    datorVal = "sax"
else:
    datorVal = "påse"

print(f"Du valde {spelarVal} och datorn valde {datorVal}")

if spelarVal == "sten" and datorVal == "sten":
    result = "tie"
elif spelarVal == "sax" and datorVal == "sax":
    result = "tie"
elif spelarVal == "påse" and datorVal == "påse":
    result = "tie"

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


print(result)