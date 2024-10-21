#include <iostream>
#include <string>
#include <vector>

using namespace std;

void convertToInitial(string *name){

    (*name) = (*name)[0];
};

int main(){
    string jacob = "Jacob";
    convertToInitial(&jacob);
    cout << jacob << endl;

    // Variabel med namnet x
    int password = 1234;
    // Pointer: Minnes adress till data
    // När man skapar: Datatyp och stjärna
    // När man bestämmer adress: och-tecken och vilken variabel
    int *ptr = &password;

    cout << "Värdet på x är " << password << endl;
    // Skriver ut adressen
    cout << ptr << endl;
    // Skriver ut värdet som adressen pekar mot
    cout << "Värdet som p pekar mot: " << *ptr << endl;
    
    // Array
    int numbers[] = {2, 4, 6, 8};
    cout << numbers[0] << endl;

    // Pointer till en array
    int *qointer = numbers;
    int *nointer = &numbers[0];
    cout << "Hallå" << *nointer << endl;
    qointer = qointer + 10;
    cout << *qointer << endl;

    // Vectors: Som en lista,
    // fast lite bättre (kan lägga till saker i efterhand.)
    vector<int> betterNumbers {
        2, 4, 6, 8
    //  0  1  2  3
    };

    // Kan ändra, hämta saker som en vanlig array
    betterNumbers[2] = 5;

    // VIKTIG!
    // push_back metoden
    // NU: Kan vi lägga till saker i efterhand.
    betterNumbers.push_back(13);

    // insert: Lägg in ett värde på en specifik plats
    // lägartill -1 på index 2
    betterNumbers.insert(betterNumbers.begin() + 2, -1);

    cout << "Alla siffror:" << endl;
    // for x in: loopar över alla saker i en lista
    for(int x : betterNumbers) {
        cout << x << endl;
    }

    return 0;
}