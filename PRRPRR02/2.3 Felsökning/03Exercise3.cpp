#include <iostream>
#include "Exception.h"

using namespace std;

class BankAccount {
private:
    double balance;
    string name;
    int age;

public:
    BankAccount(double initial, string name, int age) : balance(initial), name(name), age(age) {}

    void deposit(double amount) {
        // Del 1: Använd throw() ifall amount är negativt, eller 0.
        if(amount <= 0){
            throw Exception("I deposit funktionen får amount inte vara negativt eller noll");
        }
        balance += amount;
    }

    void withdraw(double amount) {
        // Om användaren är under 18 så används throw
        if(age < 18){
            throw Exception(name + " är under 18 och får inte ta ut pengar än!");
        }
        // Använd throw() ifall amount är mer än pengarna som finns på kontot.
        if(amount > balance){
            throw Exception("I withdraw funktionen får amount inte vara större än saldot");
        }
        balance -= amount;
    }

    double getBalance() const {
        return balance;
    }
};


int main() {
    BankAccount account(100.0, "Bartolomeus", 17);

    // Använd try.. catch, fånga och skriv ut felmeddelanden.
    try{
        // OK
        account.deposit(20.0);
    } catch(Exception e){
        cout << "Fel uppstod: " << e.getMessage() << endl;
    }
    try{
        // OK
        account.withdraw(30.0);
    } catch(Exception e){
        cout << "Fel uppstod: " << e.getMessage() << endl;
    }
    try{
        // Ska skapa ett fel.
        account.deposit(-20.0);
    } catch(Exception e){
        cout << "Fel uppstod: " << e.getMessage() << endl;
    }

    try{
        // Ska skapa ett fel.
        account.withdraw(150.0);
    } catch(Exception e){
        cout << "Fel uppstod: " << e.getMessage() << endl;
    }



    cout << "Final balance: " << account.getBalance() << endl;

    cout << "End!" << endl;

    return 0;
}