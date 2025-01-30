#include <iostream>
#include <string>
#include <vector>
#include "Exception.h"

using namespace std;

/**
 * Funktion som räknar ut hälften av ett positivt tal.
 * Del 1: Lägg till throw ifall n är negativt.
*/
float halfPositiveNumber(float n) {
    if(n < 0){
        throw Exception("Täljaren får inte vara ett negativt tal");
    }

    return n / 2.0f;
}

int main() {
    float n1 = 2.0f;
    float n2 = 12.0f;
    float n3 = 20.0f;
    float n4 = -22.0f;

    // Del 2: Lägg till try..catch och fånga felet så att programmet
    // inte kraschar.
    try{
        // OK
        cout << "Average of numbers1: " << halfPositiveNumber(n1) << endl;

        // OK
        cout << "Average of numbers2: " << halfPositiveNumber(n2) << endl;

        // OK
        cout << "Average of numbers3: " << halfPositiveNumber(n3) << endl;

        // Ska skapa en exception.
        cout << "Average of numbers4: " << halfPositiveNumber(n4) << endl;
    } catch(Exception e) {
        cout << "Fel uppstod: " << e.getMessage() << endl;
    }
    cout << "End!" << endl;

    return 0;
}