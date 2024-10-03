#pragma once

#include <iostream>
#include <string>

using namespace std;

class BankAccount {
public:
    string personnummer;
    double balance;

    void deposit(double amount) {
        balance += amount;
        cout << personnummer << ": " << "Deposited $" << amount << ". New balance: $" << balance << "\n";
    }

    void withdraw(double amount) {
        balance -= amount;
        cout << personnummer << ": " << "Withdrew $" << amount << ". New balance: $" << balance << "\n";
    }
};

