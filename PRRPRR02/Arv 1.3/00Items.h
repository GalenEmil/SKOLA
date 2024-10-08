// Pragma är till för att compilern bara ska kunna läsa denna fil en gång, ungefär.
#pragma once

#include <iostream>
#include <string>

using namespace std;

// Basklass Utility
// Har de egenskaper och funktioner som Weapon och Potion har gemensamt
class Utility {
public:
    string name;

    Utility(string n) : name(n) 
    {};

    void pickUp() {
        cout << "You found a " << name << " lying on the ground!" << endl;
    };


};

// Ärver av Utility. Får name och pickup
// Glöm inte att använda
class Potion : public Utility {
public:
    int healthRestored;
    // name behöver en konstruktor. Då använder man Utility konstruktorn till bara name
    Potion(string n, int h) : Utility(n), healthRestored(h) {}

    void use() {
        cout << "Using " << name << "! You restored " << healthRestored << " health points." << endl;
    }
};

class Weapon : public Utility {
public:
    int damage;

    Weapon(string n, int d) : Utility(n), damage(d) {}

    void attack() {
        cout << "Attacking with " << name << "! You dealt " << damage << " damage." << endl;
    }
};