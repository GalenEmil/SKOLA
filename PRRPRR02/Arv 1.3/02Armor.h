#pragma once

#include <iostream>
#include <string>

using namespace std;
// Basklass
// Sköld och bröstplatta är båda... Armor eller... för mesar
class Messmör {
public:
    string name;
    int defense;

    Messmör(string n, int d) : name(n), defense(d) {}
};

class Shield : public Messmör {
public:
    Shield(string n, int d) : Messmör(n, d) {}

    void blockAttack() {
        cout << "Blocking with " << name << ", provides " << defense << " defense." << endl;
    }
};

class Chestplate : public Messmör {
public:
    bool isMagicResistant;

    Chestplate(string n, int d, bool m) : Messmör(n, d), isMagicResistant(m) {}

    void wear() {
        cout << "Wearing " << name << ", defense level " << defense;
        if (isMagicResistant) {
            cout << ", resistant to magic attacks.";
        }
        cout << endl;
    }
};