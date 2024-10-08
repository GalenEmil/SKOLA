#include <iostream>
#include <string>
#include "12KlassPerson.h"

int main() {
    Person p("John", 25, "19920608-1623", true);

    p.introduce();
    p.haveBirthday();

    // Vad är problemet?
    // Svara här i en kommentar.
    // Ett problem med att ha en public eller oskyddad egenskap 
    // gör så att man kan ändra på objektets värden till ogiltiga värden som till exempel -5.
    
    // Egenskapen age har skapats men är en skyddad egenskap 
    // pågrund av att vi skrev private: kommandot i klassen. 
    // Så när vi försöker ändra värdet "age" så når vi inte det.
    // När du har skrivit om klassen,
    // ta bort raden nedan.
    // p.age = -5;

    // Vad är problemet?
    // Svara här i en kommentar.
    // Det finns ingen anledning att ett personnummer skulle behöva ändras så det är bäst om det är skyddat. Man kan inte byta personnummer efter födsel.
    // När du har skrivit om klassen,
    // ta bort raden nedan.
    // p.personnummer = "20040722-3292";

    p.introduce();

    Person p2("Erick", 11, "20040723-4442", false);

    // Vad är problemet?
    // Svar:
    // Jag antar att problemet innan var att det skulle stå att Erick inte hade tagit körkort än.
    // Men han kunde ändå inte haft det eftersom han är under 18 år.
    // Om man inte ändrade variabeln till ett orimligt värde i denna fil.
    // Svara här i en kommentar.
    // Ha kvar raden nedan.
    p2.acquireLicense();

    p2.introduce();

    return 0;
}
