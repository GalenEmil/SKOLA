#include <iostream>
#include "settings.h"
#include "firman.h"
#include <vector>

using namespace std;

int main(){
    /*
    cout << "Hello World" << endl;
    Settings gameSettings("100x100", false, "F4");

    gameSettings.setQuickKey("HOME");

    gameSettings.printSettings();
    */
    Personbil bil1("CNZ 391", "C40 2023", "Volvo", false);
    Personbil bil2("ANX 992", "Escape 2015", "Ford", false);
    Personbil bil3("ABC 199", "Corvette Stingray 2025", "Chevrolet", false);
    Firman bassesBilar;

    bassesBilar.läggTillBil(&bil1);
    bassesBilar.läggTillBil(&bil2);
    bassesBilar.läggTillBil(&bil3);
    cout << bil1.getRegNummer() << endl;
    cout << bil3.getMärke() << " " << bil3.getModell() << endl;

};