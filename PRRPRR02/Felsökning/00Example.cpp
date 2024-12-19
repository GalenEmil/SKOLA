#include <iostream>

using namespace std;

// Med hjälp av debuggern och en eller flera breakpoints,
// Svara på frågorna nedan.

// Frågor:
// Loop 1
// * Vad har x och y för värden innan Loop 1?
//   Svar: x = 2 och y = 6
// * Vad har x och y för värden mitt i Loop 1, när i = 1?
//   Svar: x = 12 och y = 18
// * Vad har x och y för värden efter Loop 1?
//   Svar: x = 216 och y = 234

// Loop 2
// * Vad har x och y för värden innan Loop 2?
//   Svar: x = 216 och y = 234
// * Vad har x och y för värden mitt i Loop 2, när i = 4?
//   Svar: x = 220 och y = 242
// * Vad har x och y för värden efter Loop 2?
//   Svar: x = 222 och y = 246

// Loop 3
// * Vad blir n när i=0, när i=1, och när i=2?
//   Svar: n = 0, n = 0, n = 0
// * Vilket värde har n efter loopen?
//   Svar: n = 0

// Loop 4
// * Hur många gånger kommer Loop 4 loopa? (Skriv *en specifik siffra*)
//   Svar: 4. Den kör så länge i är mindre än 4(index 0, 1, 2, 3)
// * Vad har x och y för värden efter Loop 4?
//   Svar: x = 224 och y = 240

int main() {
    int x = 2; 
    int y = 6;

    // Loop 1
    for(int i = 0; i < 2; ++i) {
        x = x * y;
        y = x + y;
    }

    // Loop 2
    for(int i = 0; i < 6; ++i) {
        x += 1;
        y += 2;
    }

    // Loop 3
    int n;
    for(int i = 1; i < 6; ++i) {
        n = x % i;
        x -= n;
        y -= n;
    }

    // Loop 4
    n = x % 27;
    for(int i = 0; i < n; ++i) {
        x++;
        y--;
    }

    cout << "Slut!" << endl;
}