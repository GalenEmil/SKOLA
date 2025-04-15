#include <iostream>

using namespace std;
struct sct {
    int t[2];
};
    struct str {
    sct t[2];
};

int main() {
    char arr[5] = { 'a', 'b', 'c', 'd', 'e' };
    for(int i = 1; i < 5; i++) {
        cout << "*";
        if((arr[i] - arr[i - 1]) % 2)
            continue;
        cout << "*";
    }
    return 0;
}