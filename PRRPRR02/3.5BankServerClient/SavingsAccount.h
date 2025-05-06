#pragma once

#include <string>
#include "Result.h"
#include "BankAccount.h"
#include "Bank.h"

/*
I BankAccount finns en virtuell metod “update()”. Syftet med denna metod är att man ska kunna lägga till flera olika klasser till olika typer av bankkonton.
*/
class SavingsAccount : public BankAccount {
protected:
    std::string accountHolderName;
    double accountBalance;
// Lägg till en ny klass, SavingsAccount som override:ar metoden update(). Den ska räkna ut och lägga till 2,00% ränta på kontot. Tanken är att banken kör update() en gång per år på alla konton.
public:
    void update() {
        double interestRate = 0.02; // 2% interest rate
        double interest = accountBalance * interestRate;
        accountBalance += interest;
    }
};