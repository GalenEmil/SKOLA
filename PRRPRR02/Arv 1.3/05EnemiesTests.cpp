#include <iostream>
#include "05Enemies.h"

using namespace std;

int main() {
    Goblin goblin(100, 15);
    goblin.attack();
    goblin.receiveDamage(20);

    Dragon dragon(300, 50, true);
    dragon.attack();
    dragon.receiveDamage(40);

    goblin.damage = 25;
    goblin.health = 80;
    cout << "Goblin's damage and health have been updated." << endl;
    goblin.attack();
    goblin.receiveDamage(30);

    dragon.breathFire = false;
    dragon.health = 260;
    cout << "Dragon no longer breathes fire and its health has been reduced." << endl;
    dragon.attack();
    dragon.receiveDamage(50);

    return 0;
}
