#include <iostream>

using namespace std;

class myVector {
public:
    // Constructor
    myVector(float x, float y) : x(x), y(y) {};

    float getX(){
        return x;
    }

    float getY(){
        return y;
    }
private:
    float x, y;
};

myVector operator+(myVector a, myVector b){
    return myVector(a.getX() + b.getX(), a.getY() + b.getY());
}

int main() {
    myVector position(12.0f, 23.0f);
    myVector velocity(1.4f, -2.0f);
}
