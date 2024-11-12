#pragma once

#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    Person(string name, string personnummer) : name(name), personnummer(personnummer) {}
    // Getters
    string getName() {
        return name;
    };

    string getPersonnummer() {
        return personnummer;
    };
    // Funktion som kan användas i andra klasser
    virtual void printDetails() = 0;

protected:
    string name;
    string personnummer;
};

