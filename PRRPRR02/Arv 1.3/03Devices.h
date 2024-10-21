#pragma once

#include <iostream>
#include <string>

using namespace std;
// Basklass
// Smartphone och Smartwatch är båda... devices
class Devices {
public:
    string manufacturer;
    int year;    

    Devices(string m, int y) : manufacturer(m), year(y) {};

    void showTime() {
        cout << "The time is 8:23!" << endl;
    }
};

class Smartphone : public Devices{
public:
    int cameraMegapixels;

    Smartphone(string m, int y, int cm) : Devices(m, y), cameraMegapixels(cm) {}

    void takePhoto() {
        cout << "Taking a photo with a " << cameraMegapixels << " megapixel camera!" << endl;
    }
};

class Smartwatch : public Devices{
public:
    bool waterproof;

    Smartwatch(string m, int y, bool wp) : Devices(m, y), waterproof(wp) {}
};