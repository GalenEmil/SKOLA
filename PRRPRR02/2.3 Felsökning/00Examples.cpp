#include <iostream>
#include <string>
#include <vector>
#include "Exception.h"

using namespace std;

float computeAverage(vector<float> numbers) {
    
    if(numbers.size() == 0){
        throw Exception("Listan var tom");
    }
    
    float sum = 0.0f;

    for(float x : numbers) {
        sum += x;
    }

    return sum / numbers.size();
}

int main() {
    vector<float> numbers1 = {1.0f, 2.0f};
    vector<float> numbers2 = {1.0f, 2.0f, 4.0f};
    vector<float> numbers3 = {-2.0f, 0.0f, 2.0f};
    vector<float> numbers4 = {};
    vector<float> numbers5 = {-2.0f, 0.0f, 2.0f};

    try{
        cout << "Average of numbers1: " << computeAverage(numbers1) << endl;
        cout << "Average of numbers2: " << computeAverage(numbers2) << endl;
        cout << "Average of numbers3: " << computeAverage(numbers3) << endl;
        cout << "Average of numbers4: " << computeAverage(numbers4) << endl;
        cout << "Average of numbers5: " << computeAverage(numbers5) << endl;
    } catch(Exception e) {
        cout << "Fel uppstod: " << e.getMessage() <<  endl;
    }
    cout << "End!" << endl;

    return 0;
}