#pragma once

#include <string>

using namespace std;

class Exception {
public:
    /*Constructor*/
    Exception(string msg) : msg(msg)
        { };
    /*Function*/
    string getMessage() {
        return msg;
    };
    /*Egenskap*/
private:
    string msg;
};