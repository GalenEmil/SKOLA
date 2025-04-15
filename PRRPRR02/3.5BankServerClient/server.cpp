#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <stdexcept>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "Bank.h"

std::string readLine(int sock) {
    std::string line;
    char c;
    ssize_t n;

    while (true) {
        n = recv(sock, &c, 1, 0);
        if (n <= 0) {
            // Error or connection closed
            return "";
        }
        if (c == '\n') {
            break;
        }
        if (c != '\r') {
            line.push_back(c);
        }
    }
    return line;
}


void sendLine(int sock, const std::string& message) {
    std::string toSend = message + "\n";
    send(sock, toSend.c_str(), toSend.size(), 0);
}

void handleClient(int clientSocket, Bank& bank) {
    std::string initialCommand = readLine(clientSocket);
    if (initialCommand.empty()) {
        return;
    }

    std::string commandType, username;
    {
        size_t spacePos = initialCommand.find(' ');
        
        if (spacePos == std::string::npos) {
            sendLine(clientSocket, "Invalid command. Use LOGIN or OPEN followed by username.");
            return;
        }

        commandType = initialCommand.substr(0, spacePos);
        username = initialCommand.substr(spacePos + 1);
    }

    BankAccount* account = nullptr;

    if (commandType == "LOGIN" || commandType == "login") {
        account = bank.getAccount(username);
        if (!account) {
            sendLine(clientSocket, "No account found for username: " + username);
            return;
        }
    } else if (commandType == "OPEN" || commandType == "open") {
        if (bank.getAccount(username) != nullptr) {
            sendLine(clientSocket, "Account already exists for username: " + username);
            return;
        }
        try {
            account = bank.createAccount(username, username);
        } catch (const std::exception& e) {
            sendLine(clientSocket, e.what());
            return;
        }
    } else {
        sendLine(clientSocket, "Invalid command. Use LOGIN or OPEN followed by username.");
        return;
    }

    sendLine(clientSocket, "Account session started for " + username);

    while (true) {
        std::string inputLine = readLine(clientSocket);
        if (inputLine.empty()) {
            break;
        }

        size_t spacePos = inputLine.find(' ');
        std::string command = inputLine;
        std::string amountStr;
        if (spacePos != std::string::npos) {
            command = inputLine.substr(0, spacePos);
            amountStr = inputLine.substr(spacePos + 1);
        }

        if (command == "BALANCE" || command == "balance") {
            double accountBalance = account->getBalance();
            sendLine(clientSocket, "Account balance: " + std::to_string(accountBalance));
        } else if (command == "DEPOSIT" || command == "deposit") {
            if (!amountStr.empty()) {
                double amount = std::stod(amountStr);
                Result depositResult = account->deposit(amount);
                sendLine(clientSocket, depositResult.getCode());
            } else {
                sendLine(clientSocket, "Error: Amount is required.");
            }
        } else if (command == "WITHDRAW" || command == "withdraw") {
            // Gör en variabel för kontots saldo
            double accountBalance = account->getBalance();
            double withdrawAmount = std::stod(amountStr);
            if (!amountStr.empty()) {
                double amount = std::stod(amountStr);
                Result withdrawResult = account->withdraw(amount);
                sendLine(clientSocket, withdrawResult.getCode());
            } else if (withdrawAmount) > accountBalance){
                sendLine(clientSocket, "Error: Insufficient funds.");
            } else {
                sendLine(clientSocket, "Error: Amount is required.");
            }
        } else {
            sendLine(clientSocket, "Unknown command");
        }
    }

    close(clientSocket);
}


int main() {
    const int PORT = 5760;
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        std::cerr << "Error creating socket\n";
        return 1;
    }

    // Allow reuse of the port quickly after the server terminates
    int opt = 1;
    setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in serverAddr;
    std::memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;      // Listen on all interfaces
    serverAddr.sin_port = htons(PORT);

    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Bind failed\n";
        close(serverSocket);
        return 1;
    }

    if (listen(serverSocket, 5) < 0) {
        std::cerr << "Listen failed\n";
        close(serverSocket);
        return 1;
    }

    std::cout << "Server started on port " << PORT << std::endl;

    Bank bank;

    while (true) {
        sockaddr_in clientAddr;
        socklen_t clientLen = sizeof(clientAddr);
        int clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientLen);
        if (clientSocket < 0) {
            std::cerr << "Error on accept\n";
            continue;
        }

        std::cout << "Client connected from "
                  << inet_ntoa(clientAddr.sin_addr) << ":"
                  << ntohs(clientAddr.sin_port) << std::endl;

        handleClient(clientSocket, bank);
    }

    close(serverSocket);
    return 0;
}
