#pragma once

#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    // Egenskaper
    string personnummer;
    double balance;
public:
    // Konstruktor
    BankAccount(string personnummer, double balance) : personnummer(personnummer), balance(balance)
    {};
    // Metoder
    void deposit(double amount) {
        if (amount > 0) 
        {
            balance += amount;
        } else
        {
            cout << "Felmeddelande(deposit)" << endl;
            return;
        }
        cout << personnummer << ": " << "Deposited $" << amount << ". New balance: $" << balance << "\n";
    }

    void withdraw(double amount) {
        // Om summan man vill ta ut är mer än eller lika med saldon så kommer det köras som vanligt. 
        if (amount <= balance && amount > 0) 
        {
            balance -= amount;
        } else
        {
            cout << "Felmeddelande(withdraw)" << endl;
            return;
        }
        cout << personnummer << ": " << "Withdrew $" << amount << ". New balance: $" << balance << "\n";
    }
};

