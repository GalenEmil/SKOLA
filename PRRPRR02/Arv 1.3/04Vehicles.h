#pragma once

#include <iostream>
#include <string>

using namespace std;
// Basklass
// Car och Bicycle är båda... fordon
class Fordon {
public:
    int maxSpeed;
    string color;

    Fordon(int m, string c) : maxSpeed(m), color(c) 
    {}
};

class Car : public Fordon{
public:
    int doors;

    Car(int m, string c, int d) : Fordon(m, c), doors(d) {}

    void go() {
        cout << "The " << color << " car honks!" << endl;
    }
};

class Bicycle : public Fordon{
public:
    bool hasBasket;

    Bicycle(int m, string c, bool h) : Fordon(m, c), hasBasket(h) {}

    void ringBell() {
        cout << "The " << color << " bicycle rings the bell!" << endl;
    }
};