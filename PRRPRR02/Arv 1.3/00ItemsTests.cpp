#include <iostream>
#include "00Items.h"

using namespace std;

int main() {
    Potion healthPotion("Health Potion", 50);
    healthPotion.pickUp();
    healthPotion.use();

    Weapon sword("Iron Sword", 25);
    sword.pickUp();
    sword.attack();

    healthPotion.healthRestored = 75;
    cout << "You upgraded the Health Potion!" << endl;
    healthPotion.use();

    sword.damage = 40;
    cout << "You sharpened the Iron Sword for more damage!" << endl;
    sword.attack();

    return 0;
}
