#include <iostream>
#include "04Vehicles.h"

using namespace std;

int main() {
    Car myCar(200, "red", 4);
    myCar.go();

    Bicycle myBike(25, "blue", true);
    myBike.ringBell();

    myCar.color = "black";
    myCar.maxSpeed = 220;
    cout << "The car has been painted black and the max speed is now " << myCar.maxSpeed << " km/h." << endl;
    myCar.go();

    myBike.color = "green";
    myBike.hasBasket = false;
    cout << "The bicycle is now green and no longer has a basket." << endl;
    myBike.ringBell();

    return 0;
}
