#include <iostream>

using namespace std;

int main(){
    // Listor
    // Arrays är en typ av lista
    int numbers[] = {10, 20, 30, 40, 50};

    // Skriv ut index 3 i listan
    //cout << numbers[2] <<endl;

    // Kan inte lägga till eller ta bort saker i en array i efterhand
    // Inte som i python

    // Kan inte mäta längd på listan
    // Len() som i python funkar inte
    // Men eftersom det inte kan ändras så är antalet alltid samma

    // Loopa igenom
    // Med for-loop
    // (skapande av en tillfällig variabel);
    // (villkoret/upprepa medan/while True);
    // (hur index ändras);
    /*
    for(int i = 0; i < 5; i += 2){
        cout << numbers[i] <<endl;
    }

    cout <<endl;

    for(int i = 0; i < 5; ++i){
        cout << numbers[i] <<endl;
    }
    */
    // Array med char(C-string)
    // Man behöver lägga till nolla i slutet för där är stringen slut
    char hello[] = {'H', 'E', 'L', 'L', 'O', '\0'};
    // Citattecken, "", och text: C++ lägger automatiskt till en nolla i slutet
    char otherhello[] = "HELLO";

    for(int i = 0; i < 5; ++i){
        cout << hello[i];
    }
    cout << endl;

    cout << hello[3] << endl;

    otherhello[3] = 'P';
    otherhello[4] = '\0';

    cout << otherhello << endl;
    return 0;
}