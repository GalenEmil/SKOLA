#include <iostream>
#include "03Devices.h"

using namespace std;

int main() {
    Smartphone myPhone("TechCorp", 2023, 108);
    myPhone.takePhoto();
    myPhone.showTime();

    Smartwatch myWatch("WearTech", 2022, true);
    myWatch.showTime();

    myPhone.cameraMegapixels = 200;
    cout << "Upgrading the smartphone's camera to 200 megapixels." << endl;
    myPhone.takePhoto();

    myWatch.waterproof = false;
    cout << "The smartwatch is no longer waterproof." << endl;
    myWatch.showTime();

    return 0;
}
