#include <iostream>

using namespace std;

class Car{
public:
    Car(string brand) : brand(brand) {};
    void printBrand(){
        cout << brand << endl;
    }
private:
    string brand;
};

int main(){
    string name = "john";
    name = "Emil";
    cout << name << endl;
    Car car1("Chevrolet");
    car1.printBrand();
    int num = 9;
    int* ptr = &num;
    cout << num << endl;
    cout << (10.0/0.0);
    int* ptr2 = nullptr;
    cout << *ptr2;

}