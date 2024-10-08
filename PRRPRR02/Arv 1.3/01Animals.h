#pragma once

#include <iostream>
#include <string>

using namespace std;
// Basklass
class Animal {
public:
    int age;
    string name;

    Animal(int a, string n) : age(a), name(n) { };
};

class Dog : public Animal {
public:
    string breed;
    // Man skriver a, n, och b eftersom det bara är konstruktorn som hanterar det.
    // Det behöver inte vara logiska namn eftersom variabelnamnen är separata
    Dog(int a, string n, string b) : Animal(a, n), breed(b) {};

    void woof() {
        cout << name << " says Woof!" << endl;
    }
};

class Snake : public Animal{
public:
    bool poisonous;

    Snake(int a, string n, bool p) : Animal(a, n), poisonous(p) {};

    void bite() {
        cout << name << " bites you!";
        if (poisonous) {
            cout << " You got poisoned!";
        }
        cout << endl;
    }
};
