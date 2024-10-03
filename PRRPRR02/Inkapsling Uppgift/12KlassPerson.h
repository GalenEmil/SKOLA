#pragma once

#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;
    string personnummer;
    bool hasLicense; // Om personen har körkort.
public:
    Person(string name, int age, string personnummer, bool hasLicense) : name(name), age(age), personnummer(personnummer), hasLicense(hasLicense)
    { };

    void introduce() {
        cout << "Hi, my name is " << name << " and I am " << age << " years old.\n";
        if(age < 18) {
            cout << "Personen är för ung för att ta körkort :(" << endl;
        } else if(hasLicense) {
            cout << "I have my driver's license! :)" << endl;
        } else {
            cout << "No driver's license! :(" << endl;
        }
    };

    void haveBirthday() {
        // Lägger på 1 i variabeln age
        age++;
        cout << name << " is now " << age << " years old!\n";
    };

    void acquireLicense() {
        hasLicense = true;
        cout << name << " passed their driving test and has their license!\n";
    }
};