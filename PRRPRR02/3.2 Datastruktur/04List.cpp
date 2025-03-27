#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    /*
     * LIST
     * En dubbel-länkad lista, där element kan läggas till och tas bort
     * effektivt från både början och slutet.
     * Långsamt och svårt att söka i en list eller hämta ett specifikt index
     */
    cout << " -- LIST -- " << endl;

    // Skapa en lista med std::list
    list<string> myList{"apple", "banana", "cherry", "cherry"};

    // Komma åt första och sista elementet
    cout << "Första elementet i listan: " << myList.front() << endl;
    cout << "Sista elementet i listan: " << myList.back() << endl;
    
    // Lägga till element
    myList.push_back("Den sista riktigt saftiga persikan"); // Lägg till i slutet
    myList.push_front("Det första äpplet"); // Lägg till i början

    // Ta bort element
    myList.pop_back(); // Tar bort sista elementet i listan
    myList.pop_front(); // Tar bort första elementet i listan

    // Ta bort ett specifikt element genom iterator
    myList.remove("cherry");

    // Test
    // myList[0];

    // Mäta antal element
    cout << "Antal frukter: " << myList.size() << endl;

    // Ta bort alla element i listan
    // myList.clear();
    
    // Loopa genom listan:
    cout << "Frukter i listan:" << endl;
    for (const string& s : myList) {
        cout << s << endl;
    }

    return 0;
}