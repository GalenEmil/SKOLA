#include <iostream>
#include <vector>

using namespace std;

int main(){
    // A vector with 3 elements
    string cars[] = {"Volvo", "BMW", "Ford"};
    int getArrayLength = sizeof(cars) / sizeof(cars[0]);
    cout << getArrayLength << endl;
    cout << sizeof(cars[0]) << endl;

    string bitar[16000000000];

}