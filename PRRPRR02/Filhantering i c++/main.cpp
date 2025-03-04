#include <iostream>
#include <vector>
#include <fstream>
#include "Exception.h"

using namespace std;

// Komplicerad funktion för att sortera ut alla separata namn till en lista.
vector<string> split(string& s, string& delimiter) {
    vector<string> tokens;
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        tokens.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    tokens.push_back(s);

    return tokens;
}

int getNamesStartingWith(){
    char fileName[100];
    cout << "Vilken fil vill du använda: " << endl;
    cin >> fileName;
    /*Skapar en pointer med FILE typen*/
    FILE *fptr;
    char buffer[100];
    fptr = fopen(fileName, "r");
    if(fptr == NULL){
        throw Exception("Filen finns inte");
    }
    
    vector<string> list;
    // Fyller listan med filens namn
    while(fgets(buffer, sizeof buffer, fptr) != NULL){
        /*cout << buffer;*/
        string name(buffer);
        // Tar bort newline-tecken om det finns
        if (name[name.length() - 1] == '\n') {
            name.erase(name.length()-1);
        }
        list.push_back(buffer);
    };

    if(list.size() == 0){
            throw Exception("Listan med namn får inte vara tom");
        }
    char letter;
    int temp_int = 0;
    cout << "Vilken bokstav vill du filtrera ut: " << endl;
    cin >> letter;
    for(string name : list){
        if(char(name[0]) == letter){
            temp_int += 1;
            }
    }

    // Gör en enda string utav hela listan
    string s = "";
    for(string name : list){
        s.append(name);
    }
    // Delimitern ska vara mellanslag
    string delimiter = " ";
    vector<string> tokens = split(s, delimiter);
    // Räknar antalet bokstäver i varje för -och efternamn
    vector<int> amountOfLet;
    for(string name : tokens){
        amountOfLet.push_back(name.size());
        cout << name.size() << endl;
    }
    // Räknar summan av bokstäver i förnamn när temporary är ett jämnt tal och vice verse för efternamn
    float sumLastName = 0;
    float sumFirstName = 0;
    int temporary = 0;
    for(int n : amountOfLet){
        if(temporary % 2 == 0){
            sumFirstName = sumFirstName + n - 1;
            temporary += 1;
        } else{
            sumLastName += n;
            temporary += 1;
        }

    }
    cout << "Totalt antal namn: " << list.size() << endl;
    cout << "Namn som börjar på " << letter << ": " << temp_int << endl;
    cout << "Procent av namn som börjar på " << letter << ": " << (float(temp_int)/list.size())*100 << "%" << endl;
    cout << "Genomsnitt antal bokstäver i förnamn " << (sumFirstName/list.size()) << endl;
    cout << "Genomsnitt antal bokstäver i efternamn " << float(sumLastName/list.size()) << endl;
    return temp_int;
}

int main() {
    /*
    vector<string> namelist;
    int temp_int;
    */
    /*
    cout << "Totalt antal namn: " << namelist.size() << endl;
    cout << "Namn som börjar på E: " << temp_int << endl;
    cout << "Procent av namn som börjar på E: " << (float(temp_int)/namelist.size())*100 << "%" << endl;
    */
    try{
        int start = getNamesStartingWith();
    } catch(Exception e){
        cout << "Fel uppstod: " << e.getMessage() << endl;
    }

    
    //fclose(fptr);
}