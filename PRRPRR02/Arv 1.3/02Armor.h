#pragma once

#include <iostream>
#include <string>

using namespace std;
// Basklass
// Sköld och bröstplatta är båda... Armor
class Armor {
public:
    string name;
    int defense;

    Armor(string n, int d) : name(n), defense(d) {}
};

class Shield : public Armor {
public:
    Shield(string n, int d) : Armor(n, d) {}

    void blockAttack() {
        cout << "Blocking with " << name << ", provides " << defense << " defense." << endl;
    }
};

class Chestplate : public Armor {
public:
    bool isMagicResistant;

    Chestplate(string n, int d, bool m) : Armor(n, d), isMagicResistant(m) {}

    void wear() {
        cout << "Wearing " << name << ", defense level " << defense;
        if (isMagicResistant) {
            cout << ", resistant to magic attacks.";
        }
        cout << endl;
    }
};