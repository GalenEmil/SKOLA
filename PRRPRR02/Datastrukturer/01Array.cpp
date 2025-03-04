#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    /*
     * VANLIG ARRAY
     * Lagra flera stycken data med samma typ, i samma variabel.
     */

    cout << " -- ARRAY -- " << endl;

    // Skapa en vanlig array som innehåller 3 saker.
    string arr[3] = {"apple", "banana", "cherry"};

    // cout << arr[4] << endl;
    // Nackdel: Man kan inte ändra en arrays storlek.
    // arr som vi skapade ovan innehåller alltid 3 saker.

    // Komma åt ett element:
    cout << arr[0] << endl;

    // Ändra ett element i en array:
    arr[0] = "papaya";

    // Loopa genom arrayen:
    cout << "Frukter i listan:" << endl;
    for (string s : arr) {
        cout << s << endl;
    }

    return 0;
}
