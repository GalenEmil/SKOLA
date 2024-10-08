#include <iostream>

using namespace std;

// Funktion som vill ha ett ord som börjar på en bokstav
// Uppgift 1

string getWordStartingWithLetter(char letter){
    string word;
    char firstLetter;
    do {
        cout << "Skriv ett ord som börjar med bokstaven " << letter << ":";
        cin >> word;
        firstLetter = word[0];
    } while(firstLetter != letter);
        return word;
    }

// Uppgift 2
// Omvandlingar
float metersToFeet(float lenM) {
    float lenF = lenM * 3.28084;
    return lenF;
}

float kilogramsToPounds(float kg){
    float lbs = kg * 2.2;
    return lbs;
}

// Uppgift 3
// Omvandling + Print

void convertMToFtAndPrint(float lenM) {
    float lenF = lenM * 3.28084;
    cout << "Längden " << lenM << " meter = " << lenF << " feet!" << endl;
}

void convertKgToLbsAndPrint(float kg) {
    float lbs = kg * 2.2;
    cout << "Vikten " << kg << " kg = " << lbs << " lbs!" << endl;
}

void convertAndPrintTemp(float celsius) {
    float fahrenheit = (celsius * 1.8f) + 32.0f;
    cout << celsius << " grader i celsius = " << fahrenheit << " fahrenheit"<< endl;
}

void convertAndPrintManyKgToLbs() {
    // Array med ett tak på 32
    float hej[32];
    // Variabel för svar
    float answer;
    // Variabel för antal vikter som angetts
    int x = 0;
    // Loop för att ta emot vikterna
    do {
        cout << "Skriv en vikt i kg: ";
        cin >> answer;
        cout << endl;
        hej[x] = answer;
        x += 1;
    } while (answer > 0);

    // Loop för att skriva ut alla värden
    for (int i = 0; hej[i] != 0; i++) {
        convertKgToLbsAndPrint(hej[i]);
        }
}
int main(){
    //string newWord = getWordStartingWithLetter('A');
    //cout << "Nytt ord: " << newWord << endl;

    float newLength1 = metersToFeet(5);
    cout << "5 meter borde bli 16.4: " << newLength1 << endl;

    float newLength2 = metersToFeet(2);
    cout << "2 meter borde bli 6.56: " << newLength2 << endl;

    float newWeight1 = kilogramsToPounds(5);
    cout << "5 kg borde bli 11.0231131: " << newWeight1 << endl;

    float newWeight2 = kilogramsToPounds(2);
    cout << "2 kg borde bli 4.40924524: " << newWeight2 << endl;

    // Borde bli 6.56
    convertMToFtAndPrint(2);
    // Borde bli 11
    convertKgToLbsAndPrint(5);
    // Borde bli 68
    convertAndPrintTemp(20);
    // Blir vad användaren bestämmer
    convertAndPrintManyKgToLbs();
}