#include <iostream>
#include <vector>

using namespace std;

int main(){
    string food = "Pizza";  // A food variable of type string
    string* ptrFood = &food;    // A pointer variable, with the name ptr, that stores the address of food

    // Output the value of food (Pizza)
    cout << food << "\n";

    // Output the memory address of food (0x6dfed4)
    cout << &food << "\n";

    // Output the memory address of food with the pointer (0x6dfed4)
    cout << ptrFood << "\n";

    string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};

    string* ptr = &cars[6];
    // Dereference av en null pointer
    cout << *ptr << endl;
}