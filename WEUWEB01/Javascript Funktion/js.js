/*
function hallo(){
    console.log("Hallo Welt");
}

function halloName(name){
    console.log("Hallo " + name);
}

function calcMaxVerstappen(a, b){
    return a + b;
}

function multiplizieren(a, b){
    return a * b;
}
hallo(); // Ausgabe: Hallo Welt
halloName("Max Verstappen"); // Ausgabe: Hallo Max Verstappen
console.log(calcMaxVerstappen(33, 44)); // Ausgabe: 77
console.log(multiplizieren(3, 4)); // Ausgabe: 12
*/

/*
tempe = 30;
if (tempe > 30){
    console.log("Es ist heiß/It's hot/Det är varmt ute");
} else{
    console.log("Es ist kalt/It's cold/Det är inte så varmt ute");
}

punkt = 601;
if (punkt > 50){
    console.log("Genehmigt/Approved/Godkänd");
}else{
    console.log("fehlgeschlagen/Failed/Underkänt");
}

if(punkt % 2 == 0){
    console.log("gerade/even/jämn");
}else{
    console.log("ungerade/odd/udda");
}

alter = 14;
if(alter < 14){
    console.log("Kind/Child/Barn");
}else if(alter <= 19){
    console.log("Jugendlicher/Teenager/Tonåring");
}else if(alter > 19){
    console.log("Erwachsener/Adult/Vuxen");
}

passwort = "1234";
if(passwort == "hemligt"){
    console.log("Zugriff gewährt/Access granted/Åtkomst beviljad");
}else{
    console.log("Zugriff verweigert/Access denied/Åtkomst nekad");
}

skottÅr = 2020;
if(skottÅr % 4 == 0 && skottÅr % 100 != 0 || skottÅr % 400 == 0){
    console.log("Schaltjahr/Leap year/Skottår");
}else{
    console.log("Kein Schaltjahr/Not a leap year/Inte ett skottår");
}
*/
/*
Skriv en switch-sats som kontrollerar värdet av en variabel, day, och skriver ut namnet på dagen på svenska, tyska eller engelska. Använd minst fem olika dagar.
Klart
Skriv en switch-sats som kontrollerar värdet av en variabel, grade, och skriver ut "Utmärkt", "Bra", "Godkänt" eller "Underkänt" baserat på betyget.

Skriv en switch-sats som kontrollerar värdet av en variabel, month, och skriver ut namnet på månaden på svenska. Använd minst sex olika månader.

Skriv en switch-sats som kontrollerar värdet av en variabel, fruit, och skriver ut namnet på frukten på svenska. Använd minst fyra olika frukter.

Skriv en switch-sats som kontrollerar värdet av en variabel, trafficLight, och skriver ut "Stanna" för rött, "Vänta" för gult och "Kör" för grönt.

Skriv en switch-sats som kontrollerar värdet av en variabel, season, och skriver ut "Vår", "Sommar", "Höst" eller "Vinter" baserat på årstiden.
*/
/*
tag = 2;
switch(tag) {
    case 1:
        console.log("Montag/Monday/Måndag");
        break;
    case 2:
        console.log("Dienstag/Tuesday/Tisdag");
        break;
    case 3:
        console.log("Mittwoch/Wednesday/Onsdag");
        break;
    case 4:
        console.log("Donnerstag/Thursday/Torsdag");
        break;
    case 5:
        console.log("Freitag/Friday/Fredag");
        break;
    default:
        console.log("Wochenende/Weekend/Helg");
        break;
}

betyg = "A";

switch(betyg){
    case "A":
        console.log("Exzellent/Excellent/utmärkt");
        break;
    case "B":
        console.log("Gut/Good/Bra");
        break;
    case "C":
        console.log("Bestanden/Passed/Godkänt");
        break;
    case "F":
        console.log("Nicht bestanden/Failed/Underkänt");
        break;
    default:
        console.log("Fehler/Error/Fel");
        break;
}

månad = 3;

switch(månad){
    case 1:
        console.log("Januari");
        break;
    case 2:
        console.log("Februari");
        break;
    case 3:
        console.log("Mars");
        break;
    case 4:
        console.log("April");
        break;
    case 5:
        console.log("Maj");
        break;
    case 6:
        console.log("Juni");
        break;
    default:
        console.log("Fehler/Error/Fel");
        break;
}

frukt = 5;
switch(frukt){
    case 1:
        console.log("Feige/Fig/Fikon");
        break;
    case 2:
        console.log("Kokosnuss/Coconut/Kokosnöt");
        break;
    case 3:
        console.log("Cashewnuss/Cashew nut/Cashewnöt");
        break;
    case 4:
        console.log("Andreas Fritiofsson/Andreas Fritiofsson/Andreas Fritiofsson");
        break;
    case 5:
        console.log("Himbeere/Raspberry/Hallon");
        break;
    default:
        console.log("Fehler/Error/Fel");
        break;
}

trafikLjus = "röd";
switch(trafikLjus){
    case "röd":
        console.log("Stanna");
        break;
    case "gul":
        console.log("Vänta");
        break;
    case "grön":
        console.log("Kör");
        break;
    default:
        console.log("Fehler/Error/Fel");
        break;
}

årstid = 3;
switch(årstid){
    case 1:
        console.log("Vår");
        break;
    case 2:
        console.log("Sommar");
        break;
    case 3:
        console.log("Höst");
        break;
    case 4:
        console.log("Vinter");
        break;
    default:
        console.log("Fehler/Error/Fel");
        break;
}
*/
/*
Loopar: for, while, do-while
Skriv en for-loop som skriver ut alla tal från 1 till 10.

Skriv en for-loop som skriver ut alla udda tal mellan 1 och 20.

Skriv en while-loop som skriver ut talen från 10 till 1.

Skriv en while-loop som skriver ut alla jämna tal mellan 1 och 20.

Skriv en do-while-loop som skriver ut talen från 1 till 5.

Skriv en do-while-loop som skriver ut talen från 5 till 1.
*/

console.log("Udda tal");
for (let i = 0; i <= 20; i++){
    if(i % 2 != 0){
        console.log(i);
    }
}

console.log("10 till 1 tal");
let i = 10;
while (i >= 0){
    console.log(i);
    i--;
}

console.log("1 till 10 tal");
for (let b = 0; b <= 10;){
    console.log(b);
    b++;
}

console.log("Jämna tal");
let j = 0;
while (j <= 20){
    if(j % 2 == 0){
        console.log(j);
    }
    j++;
}

console.log("1 till 5")
let a = 0;
do {
    console.log(a);
    a++;
} while (a <= 5);


console.log("5 till 1")
let f = 5;
do {
    console.log(f);
    f--;
} while (f > 0);
