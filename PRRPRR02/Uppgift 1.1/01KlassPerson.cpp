#include <iostream>

using namespace std;

// Klassen beskriver data och beteende hos *alla* människor.
class Person {
public:
    // Egenskaper
    string name;
    int age;
    float height;
    long int personnummer;

    // Konstruktor
    Person(string name, int age, float height, long int personnummer) : name(name), age(age), height(height), personnummer(personnummer)
    { };
    // Konstruktor för folk som inte skriver ålder
    Person(string name, float height, long int personnummer) : name(name), age(0), height(height), personnummer(personnummer)
    { };

    // Metod
    void greet() {
        cout << "Hej, jag heter " << name;
        cout << " och jag är " << age << " år gammal!" << endl;
        cout << "Jag är " << height <<  " cm lång!" << endl;
        cout << "Jag tänker inte berätta mitt personnummer!" << endl;
    };
};



int main() {
    // Använda klassen och skapa några objekt (specifika personer).
    Person dave("Dave", 19, 150, 200508233234);
    Person angela("Angela", 24, 160, 200003156969);
    Person jacob("Jacob", 27, 170, 199709112001);
    Person ted("Ted", 50, 202411111111);

    dave.greet();
    angela.greet();
    jacob.greet();
    ted.greet();

    return 0;
}