#pragma once

#include <iostream>
#include <string>

using namespace std;
// Goblin och Dragon är båda... Varelser
class Varelser {
public:
    int health;
    int damage;
    string race;
    bool breathFire;

    Varelser(int h, int d, string r, bool b) : health(h), damage(d), race(r), breathFire(b) {}
    // Konstruktor utan fire breath
    // Sätter fireBreath till false automatiskt
    Varelser(int h, int d, string r) : health(h), damage(d), race(r), breathFire(false) {}

    void attack() {
    cout << race << " attacks, dealing " << damage << " damage." << endl;
        if (breathFire == true) {
            cout << race << " breathes fire for additional damage." << endl;
            }
    }

    void receiveDamage(int d) {
        health -= d;
        cout << race << " receives " << d << " damage! Health is now " << health << "." << endl;
    }
};

class Goblin : public Varelser{
public:
    Goblin(int h, int d) : Varelser(h, d, "Goblin") {}
};

class Dragon : public Varelser{
public:
    Dragon(int h, int d, bool b) : Varelser(h, d, "Dragon", b) {}
};