# Få 1000 inloggningar i NOK flex
# Var trettionde minut kan man få en inloggning
import webbrowser
import time

counter = 0

# Det här är det viktiga
# 30 min = 30 * 60 = 1 800 sekunder
def start_countdown(seconds_countdown=3):
    while seconds_countdown > 0:
        print(f"\rNästa inloggning om {seconds_countdown} sekunder...", end="")
        time.sleep(1)
        seconds_countdown -= 1

while True:
    webbrowser.open('https://matematik.nokportalen.se/5129/elev/oversikt')  # Go to example.com
    counter += 1
    print(f"Antal inloggningar denna grind session: {counter}")
    start_countdown(1830)
#while True:
#    webbrowser.open('https://matematik.nokportalen.se/5129/elev/oversikt')  # Go to example.com
#    counter += 1