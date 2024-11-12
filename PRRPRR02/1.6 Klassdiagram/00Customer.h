#include <iostream>
#include <string>
#include "00Person.h"

using namespace std;

class Customer : public Person {
public:
    Customer(string name, string personnummer, int purchases) : Person(name, personnummer), purchases(purchases) {}

    void purchaseItem() {
        std::cout << name << " is buying an item!" << endl;
        purchases += 1;
        std::cout << name << " has now made " << purchases << " purchases!" << endl;
    };

    int getPurchases() {
        return purchases;
    };

    virtual void printDetails() {
        std::cout << name << " is a customer. They've bought " << purchases << " items!" << endl;
    };

private:
    int purchases;
};