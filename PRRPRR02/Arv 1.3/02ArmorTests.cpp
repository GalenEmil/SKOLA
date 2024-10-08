#include <iostream>
#include "02Armor.h"

using namespace std;

int main() {
    Shield ironShield("Iron Shield", 50);
    ironShield.blockAttack();

    Chestplate steelChestplate("Steel Chestplate", 80, true);
    steelChestplate.wear();

    ironShield.defense = 60;
    cout << "Upgrading defense of the Iron Shield." << endl;
    ironShield.blockAttack();

    steelChestplate.isMagicResistant = false;
    cout << "Removing magic resistance from the Steel Chestplate." << endl;
    steelChestplate.wear();

    return 0;
}
