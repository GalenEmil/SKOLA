#include <iostream>

using namespace std;

// Klassen beskriver data och beteende hos *alla* människor.
class Person {
public:
    // Egenskaper
    string name;
    int age;
    ConvenientLength height;
    long int personnummer;

    // Konstruktor
    Person(string name, int age, ConvenientLength height, long int personnummer) : name(name), age(age), height(height), personnummer(personnummer)
    { };
    // Konstruktor för folk som inte skriver ålder
    Person(string name, ConvenientLength height, long int personnummer) : name(name), age(0), height(height), personnummer(personnummer)
    { };

    // Metod
    void greet() {
        cout << "Hej, jag heter " << name;
        cout << " och jag är " << age << " år gammal!" << endl;
        cout << "Jag är " << height.byCountry() <<  " cm lång!" << endl;
        cout << "Jag tänker inte berätta mitt personnummer!" << endl;
    };
};

// Utmaning
// Jag tog land som en egenskap
class ConvenientLength {
public:
    // Egenskap
    float lenMeter;
    string land;
    // Konstruktor som tar bara längd
    ConvenientLength(float lenMeter, string land) : lenMeter(lenMeter), land(land)
    { };

    float meter() {
        return lenMeter;
    }
    float centimeter() {
        return lenMeter * 100;
    }
    float millimeter() {
        return lenMeter * 1000;
    }
    float feet() {
        return lenMeter * 3.28;
    }
    float inch() {
        return lenMeter * 39.37;
    }
    float byCountry() {
        if (land == "USA") {
            return feet();
        } else if (land == "Sverige") {
            return centimeter();
        }

    }
};


int main() {
    // Använda klassen och skapa några objekt (specifika personer).

    Person dave("Dave", 19, ConvenientLength(150, "USA"), 200508233234);
    Person angela("Angela", 24,  ConvenientLength(160, "Sverige"), 200003156969);
    Person jacob("Jacob", 27, ConvenientLength(170, "USA"), 199709112001);
    Person ted("Ted", 50, ConvenientLength(70, "Sverige"), 202411111111);
/*  
    dave.greet();
    angela.greet();
    jacob.greet();
    ted.greet();
*/
    ConvenientLength bart(1, "USA");
    ConvenientLength bartolomeus(10, "Sverige");

    cout << bart.meter() << " meter"<<endl;
    cout << bartolomeus.meter() << " meter" <<endl;
    cout <<endl;

    cout << bart.centimeter() << " cm" <<endl;
    cout << bartolomeus.centimeter() << " cm" <<endl;
    cout <<endl;
    
    cout << bart.millimeter() << " mm" <<endl;
    cout << bartolomeus.millimeter() << " mm" <<endl;
    cout <<endl;
    
    cout << bart.feet() << " feet" <<endl;
    cout << bartolomeus.feet() << " feet" <<endl;
    cout <<endl;
    
    cout << bart.inch() << " inch" <<endl;
    cout << bartolomeus.inch() << " inch" <<endl;
    cout <<endl;
    
    cout << bart.byCountry() << " " << bart.land <<endl;
    cout << bartolomeus.byCountry() << " " << bartolomeus.land <<endl;
    return 0;
}