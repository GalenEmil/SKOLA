#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    /*
     * MAP
     * Lagra par med nyckel-och-värde.
     */
    cout << " -- MAP -- " << endl;

    // Skapa en map som innehåller
    // vara och pris.
    map<string, float> db{
        {"apple", 2.0f},
        {"banana", 4.0f},
        {"cherry", 5.0f}
    };

    // Komma åt ett element.
    cout << "Pris på 'apple': £" << db["apple"] << endl;

    // Ändra ett element.
    db["hungrig"] = 5.0f;

    // Kontrollera om en nyckel finns i map
    if(db.count("apple") > 0){
        cout << "True" << endl;
    }
    
    // Ta bort en nyckel
    db.erase("apple");
    
    // Loopa genom en map?
    for(auto p : db) {
        cout << "Pris på " << p.first << ": £" << p.second << endl;
    }

    return 0;
}