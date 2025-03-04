#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    /*
     * VECTOR
     * Lagra flera stycken data med samma typ,
     * i samma variabel.
     */
    cout << " -- VECTOR -- " << endl;

    // Skapa en vector.
    vector<string> vec{"apple", "banana", "cherry"};

    // Komma åt ett element.
    cout << vec[0] << endl;

    // Ändra ett element.
    vec[0] = "papaya";

    // Lägg till
    vec.push_back("ananas");

    // Ta bort
    vec.erase(vec.begin() + 2);

    // Loopa genom vectorn:
    cout << "Frukter i listan:" << endl;
    for (string s : vec) {
        cout << s << endl;
    }
    cout << vec[0] << " or " << vec.front() << endl;
    cout << vec.back() << " eller " << vec[-1] << endl;
    return 0;
}