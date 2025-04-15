#pragma once

#include <string>
#include <stdexcept>
#include <map>
#include "BankAccount.h"


class Bank {
private:
    std::map<std::string, BankAccount*> accounts;

public:
    Bank() = default;

    ~Bank() {
        for (auto& kv : accounts) {
            delete kv.second;
        }
    }

    BankAccount* createAccount(const std::string& username, const std::string& accountHolderName) {
        if (accounts.find(username) != accounts.end()) {
            throw std::invalid_argument("Account with this username already exists.");
        }
        BankAccount* newAccount = new BankAccount(accountHolderName, 0.0);
        accounts[username] = newAccount;
        return newAccount;
    }

    BankAccount* getAccount(const std::string& username) {
        auto it = accounts.find(username);
        if (it != accounts.end()) {
            return it->second;
        }
        return nullptr;
    }

    void update() {
        for (auto& kv : accounts) {
            kv.second->update();
        }
    }
};