#include <iostream>

using namespace std;

int main() {
    int* ptr = nullptr;

    int arr[3] = {1, 2, 3};

    ptr = arr;

    cout << "corn on the cob: " << *(ptr + 5) << endl;

    return 0;
}
