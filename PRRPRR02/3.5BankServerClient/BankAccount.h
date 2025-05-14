#pragma once

#include <string>
#include "Result.h"

class BankAccount {
protected:
    std::string accountHolderName;
    double accountBalance;

public:
    BankAccount(const std::string& holderName, double initialBalance)
        : accountHolderName(holderName), accountBalance(initialBalance) {}

    std::string getAccountHolderName() const {
        return accountHolderName;
    }

    void setAccountHolderName(const std::string& name) {
        accountHolderName = name;
    }

    double getBalance() const {
        return accountBalance;
    }

    Result deposit(double amount) {
        if (amount > 0) {
            accountBalance += amount;
            return Result("SUCCESS");
        } else {
            return Result("Error: Deposit amount must be positive.");
        }
    }

    Result withdraw(double amount) {
        if (amount > 0) {
            if (amount <= accountBalance) {
                accountBalance -= amount;
                return Result("SUCCESS");
            } else {
                return Result("Error: Insufficient funds for withdrawal.");
            }
        } else {
            return Result("Error: Withdrawal amount must be positive.");
        }
    }

    virtual void update() {
        // do absolutely nothing
        
    }
};