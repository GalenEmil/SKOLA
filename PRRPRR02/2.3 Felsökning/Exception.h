#pragma once

#include <string>

using namespace std;

class Exception {
public:
    Exception(string msg) : msg(msg)
        { };

    string getMessage() {
        return msg;
    };
private:
    string msg;
};