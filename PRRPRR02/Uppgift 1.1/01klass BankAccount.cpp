#include <iostream>

using namespace std;

class BankAccount {
public:
    long int personnummer;
    float balance;

    // Konstruktor
    BankAccount(float balance, long int personnummer) : balance(balance), personnummer(personnummer)
    { };

    void deposit(float pengar) {
        balance += pengar;
        cout << "Pengar som lagts till: " << pengar << " kr" << endl;
        cout << "Nuvarande saldo: " << balance << " kr" << endl;
    }
    void withdraw(float pengar) {
        balance -= pengar;
        cout << "Pengar som dragits från kontot: " << pengar << " kr" << endl;
        cout << "Nuvarande saldo: " << balance << " kr" << endl;
    }

};
int main () {
    BankAccount konto1(31000, 198806022141);
    BankAccount konto2(100, 200207213492);
    konto1.withdraw(10000);
    konto2.deposit(2000);
}