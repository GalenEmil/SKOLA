#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // TODO: Skapa en vector för alla ord i namnet.
    // Klart
    
    // Skriv ut instruktioner.
    cout << "Skriv ditt namn, ett ord i taget." << endl;
    cout << "Du kan avsluta genom att trycka på ENTER." << endl;
    
    // Loop som ska hämta in alla ord, ett i taget,
    // tills användaren avslutar.
    string npart;
    vector<string> lista{

    };
    while(true) {
        // getline är som en cin(see in)
        getline(cin, npart);
        // TODO: Lägg till ordet i vectorn.
        lista.push_back(npart);
        // Om användaren däremot trycker på ENTER igen, alltså
        // har gett hela namnet, ska vi då avsluta istället.
        // Om antalet karaktärer är 0 i npart så är det ENTER
        // Jag tror inte det var på detta vis du ville att vi skulle göra
        if(npart.size() == 0){
            break;
        }
    }
    
    // TODO: Skriv ut användarens fullständiga namn.
    cout << "Ditt fullständiga namn är: ";
    for(string x : lista){
        cout << x;
        cout << ' ';

    }
    cout << endl << endl;

    // TODO: Skriv ut användarens initialer.
    cout << "Dina initialer är: ";
    for(string x : lista){
        cout << x[0];
    }
    cout << endl << endl;
    return 0;
}