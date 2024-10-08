#pragma once

#include <iostream>
#include <string>

using namespace std;

class Goblin {
public:
    int health;
    int damage;

    Goblin(int h, int d) : health(h), damage(d) {}

    void attack() {
        cout << "Goblin attacks, dealing " << damage << " damage." << endl;
    }

    void receiveDamage(int d) {
        health -= d;
        cout << "Goblin receives " << d << " damage! Health is now " << health << "." << endl;
    }
};

class Dragon {
public:
    int health;
    int damage;
    bool breathFire;

    Dragon(int h, int d, bool b) : health(h), damage(d), breathFire(b) {}

    void attack() {
        cout << "Dragon attacks, dealing " << damage << " damage." << endl;
        if (breathFire) {
            cout << "Dragon breathes fire for additional damage." << endl;
        }
    }

    void receiveDamage(int d) {
        health -= d;
        cout << "Dragon receives " << d << " damage! Health is now " << health << "." << endl;
    }
};