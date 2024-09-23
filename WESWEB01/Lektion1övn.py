temp = float(input("Vad är temperaturen? "))

if temp <= 10:
    print("Ganska kyligt!")
elif temp < 20 and temp > 10:
    print("Lite kyligt!")
elif temp >= 20 and temp < 30:
    print("Lite varmt!")
elif temp >= 30:
    print("Ganska varmt!")
