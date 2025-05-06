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
#include "SavingsAccount.h"

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
    /*
    spacePos är en variabel som används för att 
    hitta positionen för det första mellanslaget i strängen initialCommand.
    Detta mellanslag är viktigt då det delar upp kommandot och användarnamnet.

    subString används för att hämta kommandot och användarnamnet från stringen.
    Och sedan lägga in det i två nya string variabler: commandType och username.

    Sedan används den för att skapa två substrings: en för kommandot (från början av strängen till mellanslaget) och en för användarnamnet (från mellanslaget till slutet av strängen).
    */
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
    /*
    account behöver definieras så att den kan användas senare i koden.
    Det går inte att skapa den i if-satsen eftersom den då inte går att använda senare.
    */
    BankAccount* account = nullptr;

    if (commandType == "LOGIN" || commandType == "login") {
        account = bank.getAccount(username);
        if (!account) {
            sendLine(clientSocket, "No account found for username: " + username);
            return;
        }
    } else if (commandType == "OPEN" || commandType == "open") {
        if (bank.getAccount(username) != nullptr) {
            /*
            std::cout << "What type of account do you want to open?" << std::endl;
            std::cout << "1. Personal account" << std::endl;
            std::cout << "2. Savings account" << std::endl;
            std::string accountType = readLine(clientSocket);
            if (accountType == "1") {
                account = bank.createAccount(username, username);
            } else if (accountType == "2") {
                account = new SavingsAccount(username, username);
                bank.createAccount(username, username);
            } else {
                sendLine(clientSocket, "Invalid account type. Use 1 for Personal or 2 for Savings.");
                return;
            }
            */
            sendLine(clientSocket, "Account already exists for username: " + username);
            return;
        }
        /*
        createAccount() kan skapa ett fel om det redan finns ett konto med samma användarnamn.
        Om man inte fångar felet med try..catch så kommer programmet att krascha och stänga ner servern.
        */
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

    /*
    7.
    a.
    Denna del av koden ska upprepas så att alla kommandon som användaren skriver tas emot.
    Den kommer att fortsätta tills användaren skriver en tom rad (eller stänger ner klienten).
    b.
    Substringen delar upp strängen i två delar: kommandot och beloppet.
    */

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
            if (!amountStr.empty()) {
                double amount = std::stod(amountStr);
                Result withdrawResult = account->withdraw(amount);
                sendLine(clientSocket, withdrawResult.getCode());
            } else {
                sendLine(clientSocket, "Error: Amount is required.");
            }
        } else if (command == "LOGOUT" || command == "logout") {
            sendLine(clientSocket, "Account session ended for " + username);
            break;
        } else if (command == "CLOSE" || command == "close") {
            if (account->getBalance() > 0){
                sendLine(clientSocket, "Error: Can not close account with balance, withdraw balance first.");
            } else {
                /*Ta bort kontot från banken*/
                bank.removeAccount(username); // Call the removeAccount function
                delete account; // Delete the account object
                sendLine(clientSocket, "Account closed for " + username);
                break;
        }

        } else {
            sendLine(clientSocket, "Unknown command");
        }
    }

    close(clientSocket);
}


int main() {
    /*
    1.
    En socket i i C++ är en åtkomstpunkt/objekt för kommunikation mellan 
    två program, antingen på samma dator eller över ett nätverk.
    Den gör alltså så att programmet kan skicka och ta emot data över nätverket.
    */
    /*
    2.
    I socket() funktionen finns det parameterar:
    AF_INET delen bestämmer i vilket format IP-adressen ska vara, i det här fallet IPv4.
    SOCK_STREAM bestämmer att TCP protokollet ska användas för att skicka data.
    0 gör så att systemet ska välja rätt protokoll automatiskt.
    */
    /*
    3.
    På engelska är det "socket file descriptor"
    och det är ett heltal, eftersom det är en int, som identifierar socketen
    */
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
    /*
    a.
    Funktionen bind() gör så att socketen kan lyssna efter inkommande anslutningar.
    Den gör det genom att koppla socketen till en specifik adress och portnummer.
    b.
    Den tar först socket file descriptor värdet som skapades med socket() funktionen.
    (sockaddr*)&serverAddr skapar en pointer typ av adressen
    sizeof(serverAddr) är storleken på adressen så servern vet hur mycket data den ska läsa. 
    c.
    Det ska ge returvärdet 0 om det lyckas, annars -1.
    Det är därför skrivet < 0 i if-satsen.
    */
    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Bind failed\n";
        close(serverSocket);
        return 1;
    }
    /*
    a.
    Funktionen listen() markerar socketen som passiv och gör den redo att ta emot inkommande anslutningar
    b.
    Socket file descriptor värdet är en parameter
    Numret efter det är hur många anslutningar som det max får vara
    c.
    Det ska ge returvärdet 0 om det lyckas, annars -1.
    */
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
        /*
        a.
        Funktionen accept() accepterar en ny anslutning från en klient och skapar en ny socket för den anslutningen.
        b.
        socket file descriptor värdet är en parameter
        (sockaddr*)&clientAddr är adressen till klienten som ansluter som en pointer
        &clientLen är en pointer som pekar till storleken på klient adressen
        c.
        Det ska ge returvärdet 0 om det lyckas, annars -1.
        */
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
