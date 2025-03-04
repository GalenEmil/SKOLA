#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// Funktion för att få värdet för en nyckel
float getValue(string userKey, vector<string> keys, vector<float> values){
    for(int i = 0; i < keys.size(); i++){
        if(keys[i] == userKey){
            return values[i];
        }            
    };
}

int main() {
    /*
     * MAP
     * Lagra par med nyckel-och-värde.
     */
    cout << " -- MAP -- " << endl;

    // Skapa en map från grunden med hjälp av vectorer bara
    // som innehåller vara och pris.
    vector<string> keys{"apple", "banana", "cherry"};
    vector<float> values{2.0f, 4.0f, 5.0f};


    // Komma åt ett element.
    cout << "Pris på 'apple': £" << getValue("apple", keys, values) << endl;

    // Ändra ett element.
    values[0] = 0.0f;

    // Kontrollera om en nyckel finns i map
    /*
    if(db.count("apple") > 0){
        cout << "True" << endl;
    }
    */
    // Ta bort en nyckel
    // db.erase("apple");
    
    // Loopa genom en map?
    /*
    for(auto p : db) {
        cout << "Pris på " << p.first << ": £" << p.second << endl;
    }
    */
    return 0;
}