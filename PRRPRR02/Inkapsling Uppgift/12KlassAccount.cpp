#include <iostream>
#include <string>
#include "12KlassAccount.h"

int main() {
    BankAccount account1;
    account1.personnummer = "19920608-1623";
    account1.balance = 1000.00;

    BankAccount account2;
    account2.personnummer = "20020405-9220";
    account2.balance = 200.00;

    account1.deposit(200.00);
    account1.withdraw(500.00);

    // Vad är problemet?
    // Svara här i en kommentar.
    // När du har skrivit om klassen,
    // ta bort raden nedan.
    account1.balance = -1000;

    // Vad är problemet?
    // Svara här i en kommentar.
    // Ha kvar raden nedan (den borde skriva ut ett fel.)
    account2.withdraw(2000.00);

    return 0;
}