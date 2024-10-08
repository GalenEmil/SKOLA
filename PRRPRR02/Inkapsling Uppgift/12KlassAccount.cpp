#include <iostream>
#include <string>
#include "12KlassAccount.h"

int main() {
    /*
     Det här funkar inte längre för att det nu finns en konstruktor
    BankAccount account1;
    account1.personnummer = "19920608-1623";
    account1.balance = 1000.00;

    BankAccount account2;
    account2.personnummer = "20020405-9220";
    account2.balance = 200.00;
    */
    BankAccount account1("19920608-1623", 1000.00);
    BankAccount account2("20020405-9220", 200.00);

    account1.deposit(200.00);
    account1.withdraw(500.00);

    // Vad är problemet?
    // Svara här i en kommentar.
    // Svar: Jag gjorde balance till en privat egenskap. Detta innebär att vi inte kan nå den utanför klassen.
    // Problemet innan var att man kunde ändra egenskapen till ett orimligt värde som -1000.

    // När du har skrivit om klassen,
    // ta bort raden nedan.
    // account1.balance = -1000;

    // Vad är problemet?
    // Svara här i en kommentar.
    // Svar: Inget hindrar withdraw funktionen att ta ut mer pengar än vad man har. Den borde skriva ut ett felmeddelande.

    // Ha kvar raden nedan (den borde skriva ut ett fel.)
    account2.withdraw(2000.00);
    account1.deposit(-1000);
    account2.withdraw(-1000);

    return 0;
}