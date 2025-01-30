#include <iostream>
#include <string>
#include "Exception.h"

using namespace std;

/**
 * Funktion som hämtar tecknet i mitten av en string.
 * Del 1: Lägg till throw ifall stringen har 0 tecken,
 * eller om stringen har ett jämnt antal tecken.
*/
char getMiddleCharacter(string n) {
    if(n.size() == 0){
        throw Exception("Stringen får icke vara tom");
    }
    if(n.size() % 2 == 0){
        throw Exception("Stringen måste ha ett ojämnt antal tecken");
    }
    return n[n.size() / 2];
}

int main() {
    string testStr1 = "Hello";
    string testStr2 = "world";
    string testStr3 = "";
    string testStr4 = "me";

    // Del 2: Lägg till try..catch och fånga felet så att programmet
    // inte kraschar.
    try{
        // OK
        cout << "middle char of str 1 is " << getMiddleCharacter(testStr1) << endl;

    } catch(Exception e){
        cout << "Fel uppstod: " << e.getMessage() << endl;
    }

    try{
        // OK
        cout << "middle char of str 2 is " << getMiddleCharacter(testStr2) << endl;
    } catch(Exception e){
        cout << "Fel uppstod: " << e.getMessage() << endl;
    }
    try{
        // Ska skapa en exception.
        cout << "middle char of str 3 is " << getMiddleCharacter(testStr3) << endl;   
    }catch(Exception e){
        cout << "Fel uppstod: " << e.getMessage() << endl;
    }
    try{
        // Ska skapa en exception.
        cout << "middle char of str 4 is " << getMiddleCharacter(testStr4) << endl;
    }catch(Exception e){
        cout << "Fel uppstod: " << e.getMessage() << endl;
    }

    cout << "End!" << endl;

    return 0;
}