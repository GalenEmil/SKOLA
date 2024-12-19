#include <iostream>
#include <vector>

using namespace std;

// Frågor:
// * Innan du ändrar något: Vilka funktioner körs?
//   Körs bara några av Mega, Giga, Tera, Exa, eller alla?
//   Svar: Exa, Tera, Giga körs
// * I cascadingExa: Vad har sum och result för värden innan cascadingTera körs?
//   Svar: sum = 41, result = 6
// * I cascadingGiga, raden med if(result == 0).
//   Vilket värde kan du skriva istället för 0 i if-satsen
//   så att cascadingMega körs?
//   Svar: if(result > 0) eller if(result != 0) eller if(result == 8)
// * Tillbaka i main(): Vilket värde har v efter att alla funktioner
//   körs, *efter* att du gjorde ändringen så att cascadingMega körs?
//   Svar: 26, 33, 32, 29, 31 med mera. 
//   Listan är 6 lång och i CascadingMegafunction så försöker den ta index 7 och 8 vilket bara tar ett random tal från minnet.

int cascadingMegafunction(int *list, int n, int &p) {
    int sum = 0;

    for(int i = 0; i < n; ++i) {
        sum += list[i];
        cout << list[i] << endl;
    }

    int result = sum % 17 - 1;

    p += result % 9;

    return 0;
}
// JA
int cascadingGigafunction(int *list, int n, int &p) {
    int sum = 0;

    for(int i = 0; i < n; ++i) {
        sum += list[i];
        cout << list[i] << endl;
    }

    int result = sum % 19 + 5;
    if(result == 8) {
        return cascadingMegafunction(list, result, p += sum % 3 + 1);
    } else {
        return 0;
    }
}
// JA
int cascadingTerafunction(int *list, int n, int &p) {
    int sum = 0;

    for(int i = 0; i < n; ++i) {
        sum += list[i];
        cout << list[i] << endl;
    }

    int result = sum % 17 - 1;
    if(result % 3 == 0) {
        return cascadingGigafunction(list, result, p += sum % 12);
    } else {
        return 0;
    }
}
// JA
int cascadingExafunction(int *list, int n, int &p) {
    int sum = 0;

    for(int i = 0; i < n; ++i) {
        sum += list[i];
        cout << list[i] << endl;
    }

    int result = sum % 7;
    if(result % 3 == 0) {
        return cascadingTerafunction(list, result, p += sum % 10);
    } else {
        return 0;
    }
}

int main() {
    int numbers[] = {
        2, 3, 5, 7, 11, 13
    };

    int v = 20;

    cout << cascadingExafunction(numbers, 6, v) << endl;
    cout << v << endl;
    return 0;
}
