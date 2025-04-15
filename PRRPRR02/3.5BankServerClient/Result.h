#pragma once

#include <string>

class Result {
private:
    std::string code;
    bool success;

public:
    Result(const std::string& c)
        : code(c), success(c == "SUCCESS") {}

    std::string getCode() const {
        return code;
    }

    bool wasSuccess() const {
        return success;
    }
};