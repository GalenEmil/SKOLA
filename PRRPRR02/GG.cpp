#include <iostream>

using namespace std;

// Temp konverterare

// Funktion som gör om Celsius till Fahrenheit
float convertCToF(float celsius){
    float fahrenheit = (celsius * 1.8f) + 32.0f;
    return fahrenheit;
}

// Funktion som både konverterar temp och printar ut resultatet
// Void gör så att det inte behövs ett returvärde
//
void convertCToFAndPrint(float celsius){
    float fahrenheit = (celsius * 1.8f) + 32.0f;
    cout << celsius << " grader c = " << fahrenheit << " grader f" << endl;
}

// Funktion som vill ha ett ord som börjar på A
string getWordStartingWithA(){
    string word;
    do {
        cout << "Skriv ett ord som börjar med A: ";
        cin >> word;
    } while(word[0] != 'A');

    return word;
}

int main(){
    float tempc1 = 24.0f;
    float tempc2 = 33.2f;
    convertCToFAndPrint(tempc1);
    convertCToFAndPrint(tempc2);
    string newWord = getWordStartingWithA();
    cout << "Du valde ordet " << newWord << endl;
}