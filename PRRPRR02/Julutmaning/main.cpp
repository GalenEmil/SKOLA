#include <numeric>
#include <iostream>
#include <functional>
#include <vector>
#include <stdexcept>

using namespace std;

int hocusPocus() {
    auto q = vector<int>{3, 6, 12};
    int result = accumulate(q.begin(), q.end(), 0);

    return (result > 0 ? result : -result) / 1;
}

int losingFocus() {
    auto q = vector<int>{3, 3, 3};
    int result = accumulate(q.begin(), q.end(), 0);

    return (result > 0 ? result : -result) / 1;
}

int plagueOfLocusts() {
    auto q = vector<int>{12, 14, 38};
    int result = accumulate(q.begin(), q.end(), 0);

    return (result > 0 ? result : -result) / 1;
}

int cascadingYottafunction(int mega) {
    int kilo = mega;
    int giga = hocusPocus();

    for(int i = mega; i < giga; ++i) {
        kilo += 5;
    }

    kilo -= 8;

    return kilo;
}

int cascadingDeltafunction(int mega) {
    int kilo = mega;
    int iota = losingFocus();

    for(int i = mega; i < iota; ++i) {
        kilo += iota - 1;
    }

    kilo -= 1;

    return kilo;
}

int cascadingZetafunction(int mega) {
    int kilo = mega;
    int exa = plagueOfLocusts();

    for(int i = mega; i < exa; ++i) {
        kilo += exa / 32;
    }

    kilo -= 2;

    return kilo;
}

int verifyPony(int code) {
    int p = cascadingYottafunction(0);
    if(code % p == 0) {
        return 1;
    } else {
        return 0;
    }
}

int verifyXbox(int code) {
    int p = cascadingDeltafunction(0);
    if(code % p == 0) {
        return 1;
    } else {
        return 0;
    }
}

int verifyLamborghini(int code) {
    int p = cascadingZetafunction(-1);
    if(code % p == 0) {
        return 1;
    } else {
        return 0;
    }
}

int hexToInt(const std::string& hexStr) {
    if (hexStr.empty()) {
        throw invalid_argument("Input string is empty");
    }

    int result = 0;

    for (size_t i = 0; i < hexStr.length(); ++i) {
        char c = hexStr[i];
        int value;

        if (std::isdigit(c)) {
            value = c - '0';
        } else if (std::isalpha(c)) {
            if (c >= 'a' && c <= 'f') {
                value = 10 + (c - 'a');
            } else if (c >= 'A' && c <= 'F') {
                value = 10 + (c - 'A');
            } else {
                throw invalid_argument("Invalid hexadecimal character: " + std::string(1, c));
            }
        } else {
            throw invalid_argument("Invalid character in hexadecimal string: " + std::string(1, c));
        }

        result = (result * 16) + value;
    }

    return result;
}

// 312
// 2 + 10 + 300

// 0 1 2 3 4 5 6 7 8 9 10
// 0 1 2 3 4 5 6 7 8 9 A B C D E F 10

// FC32FF 

// 255 = FF
// xi = 11

typedef function<int(int)> PreCascader;

int main() {
    cout << cascadingYottafunction(0) << endl;

    cout << cascadingDeltafunction(0) << endl;

    cout << cascadingZetafunction(-1) << endl;


    string code;
    cout << "Enter the code you received from Santa: " << endl;
    cin >> code;
    int slightlyDemystifiedCode;
    try {
        slightlyDemystifiedCode = hexToInt(code);
    } catch(exception e) {
        cout << "Did you type your code wrong? Try again!" << endl;
        return 0;
    } 

    vector<PreCascader> preCascaders = {
        verifyPony, verifyXbox, verifyLamborghini
    };

    vector<string> presentMatrix = {
        "Pony", "Xbox", "Lamborghini"
    };

    vector<string> acquiredPresents;

    int numPresents = 0;

    for(int i = 0; i < presentMatrix.size(); ++i) {
        auto const &preCascader = preCascaders[i];
        string present = presentMatrix[i];

        if(preCascader(slightlyDemystifiedCode)) {
            acquiredPresents.push_back(present);
        }
    }

    for(string const &present : acquiredPresents) {
        cout << "You receive a " << present << " this year!" << endl;
    }

    if(acquiredPresents.size() >= 3) {
        cout << "Goodness! Santa is feeling generous this year." << endl;
    } else if(acquiredPresents.size() == 0) {
        cout << "Sorry! You won't receive any presents this year." << endl;
        cout << "Perhaps your code is invalid, or maybe you ended up on Santa's naughty list. :(" << endl;
    }

    return 0;
}