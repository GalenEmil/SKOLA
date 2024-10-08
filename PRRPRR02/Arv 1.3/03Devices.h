#pragma once

#include <iostream>
#include <string>

using namespace std;
// Basklass
// Smartphone och Smartwatch är... devices, eller var... bättre förr?
class Detvarbättreförr {
public:
    string manufacturer;
    int year;    

    Detvarbättreförr(string m, int y) : manufacturer(m), year(y) {};

    void showTime() {
        cout << "The time is 8:23!" << endl;
    }
};

class Smartphone : public Detvarbättreförr{
public:
    int cameraMegapixels;

    Smartphone(string m, int y, int cm) : Detvarbättreförr(m, y), cameraMegapixels(cm) {}

    void takePhoto() {
        cout << "Taking a photo with a " << cameraMegapixels << " megapixel camera!" << endl;
    }
};

class Smartwatch : public Detvarbättreförr{
public:
    bool waterproof;

    Smartwatch(string m, int y, bool wp) : Detvarbättreförr(m, y), waterproof(wp) {}
};