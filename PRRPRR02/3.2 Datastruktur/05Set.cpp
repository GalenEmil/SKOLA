#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    /*
     * SET
     * En datastruktur som innehåller unika element (sorterade, inga dubletter).
     * Sorterar automatiskt i bokstavsordning   
     */
    cout << " -- SET -- " << endl;

    // Skapa ett set
    set<string> s = {"apple", "banana", "cherry"};

    // Lägga till element
    s.insert("Persika"); // Lägg till ett element
    s.insert({"Vattenmelon", "Nätmelon"}); // Lägg till flera element samtidigt

    s.insert("Persika"); // Försöker lägga till "Persika" igen. 
                         // Men den försvinner för att det är en dublett

    // Försöka ta bort ett element
    s.erase("Nätmelon");

    // Kontrollera om ett element finns
    bool hasElement = s.find("Vattenmelon") != s.end(); // find() hittar ett element
    if(hasElement){
        cout << "Vattenmelon finns i setet" << endl;
    }else{
        cout << "Vattenmelon finns inte med i setet" << endl;
    }
    // Mäta antal element
    cout << "Antal element: " << s.size() << endl;

    // Ta bort alla element ur set
    // s.clear();

    // Loopa genom setet (sorterade!)
    cout << "Frukter i setet:" << endl;
    for (const string& frukt : s) {
        cout << frukt << endl;
    }

    return 0;
}