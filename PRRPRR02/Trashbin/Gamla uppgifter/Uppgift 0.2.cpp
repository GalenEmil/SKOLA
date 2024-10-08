#include <iostream>


using namespace std;

int main() {
    // 1
    // Lista med värden
    float list[] = {23.4, 18.0, 34.9, 42.3, 29.2, 25.5};

    // 2
    // Skriv ut fjärde och sista värdet
    cout << list[3] << endl;
    cout << list[5] << endl;
    // 3
    // Loopa och skriv ut
    for (int i = 0; i < 6; ++i) {
        cout << list[i] << " / ";
    }
    cout << endl;
    // 4
    // Hitta största siffran
    float big = 0;
    for (int i = 0; i < 6; ++i) {
        float current = list[i];
        if (current >= big){
            big = current;
        } 
        if (i == 5) {
            cout << big << " är det största talet i listan" << endl;
        }
    }
    // 5
    // Summan av listan
    float sum;
    for (int i = 0; i < 6; ++i) {
        sum += list[i];
    }
    cout << sum << " är summan!" << endl;
}
