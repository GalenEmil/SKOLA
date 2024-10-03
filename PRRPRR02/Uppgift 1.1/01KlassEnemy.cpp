#include <iostream>
#include <cstdlib>

using namespace std;

// Klassen beskriver data och beteende hos *alla* fiender.
class Enemy {
public:
    // Egenskaper
    string type;
    int x, y;
    int strength;
    string status;

    // Konstruktor
    Enemy(string type, int x, int y, int strength, string status) : type(type), x(x), y(y), strength(strength), status(status)
    { };
    // Konstruktor utan "status" egenskap
    Enemy(string type, int x, int y, int strength) : type(type), x(x), y(y), strength(strength), status("Healthy")
    { };
    // Konstruktor som bara tar emot x och y
    Enemy(int x, int y) : type("Commoner"), x(x), y(y), strength(3), status("Healthy")
    { };
    // Metod
    int attack() {
        // Slumpar ett tal 1-6 (en d6).
        int modifier = rand() % 6 + 1;
        if (status == "Paralyzed") {
            return 0;
        }
        return strength + modifier;
    }
};


int main() {
    // Behövs innan man kan använda rand().
    srand(time(NULL));

    // Använda klassen och skapa några objekt (specifika personer)
    Enemy enemy1("Goblin", 12, 24, 5);
    Enemy enemy2("Angry Seagull", 0, 0, 2);
    Enemy enemy3(111, 222);
    Enemy boss("Final Boss", 23, 12, 100, "Paralyzed");

    cout << enemy1.type << " attacks you, dealing " << enemy1.attack() << " damage!" << endl;
    cout << enemy2.type << " attacks you, dealing " << enemy2.attack() << " damage!" << endl;
    cout << enemy3.type << " attacks you, dealing " << enemy3.attack() << " damage!" << endl;
    cout << boss.type << " attacks you, dealing " << boss.attack() << " damage!" << endl;

    return 0;
}