#include <iostream>
#include "01Animals.h"

using namespace std;

int main() {
    Dog myDog(3, "Buddy", "Golden Retriever");
    cout << "Dog's name: " << myDog.name << endl;
    cout << "Dog's age: " << myDog.age << endl;
    cout << "Dog's breed: " << myDog.breed << endl;
    myDog.woof();

    myDog.age = 4;
    myDog.name = "Max";
    cout << "Dog's new name: " << myDog.name << endl;
    cout << "Dog's new age: " << myDog.age << endl;
    myDog.woof();

    Snake mySnake(5, "Slither", true);
    cout << "Snake's name: " << mySnake.name << endl;
    cout << "Snake's age: " << mySnake.age << endl;
    cout << "Is the snake poisonous? " << (mySnake.poisonous ? "Yes" : "No") << endl;
    mySnake.bite();

    mySnake.age = 6;
    mySnake.name = "Venom";
    mySnake.poisonous = false;
    cout << "Snake's new name: " << mySnake.name << endl;
    cout << "Snake's new age: " << mySnake.age << endl;
    cout << "Is the snake poisonous? " << (mySnake.poisonous ? "Yes" : "No") << endl;
    mySnake.bite();

    return 0;
}
