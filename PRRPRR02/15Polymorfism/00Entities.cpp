#include <iostream>
#include <string>
#include "00Entities.h"
#include <vector>
using namespace std;

int main() {
    // ---- Innan polymorfism ----
    cout << "Innan polymorfism:" << endl;

    // Skapa alla entities.
    Soldier meanie("Meanie", 30);
    PetDog petDog("Fido", "yellow");
    Bullet bullet(5);

    // Grafikkod: "Rita" alla entities.
    meanie.draw();
    petDog.draw();
    bullet.draw();


    // ---- Efter polymorfism ----
    cout << "Efter polymorfism:" << endl;

    vector<NPC*> lista = {&meanie, &petDog, &bullet};

    for(NPC *npc : lista){
        npc->draw();
    };
    
    // ...

    return 0;
}