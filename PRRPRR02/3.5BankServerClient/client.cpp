#include <iostream>
#include <string>
#include <cstring>
#include <limits>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

std::string readLine(int sock) {
    std::string line;
    char c;
    ssize_t n;

    while (true) {
        n = recv(sock, &c, 1, 0);
        if (n <= 0) {
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

int main() {
    std::string serverIp;
    int serverPort;
    
    std::cout << "Enter the server IP: ";
    std::getline(std::cin, serverIp);

    std::cout << "Enter the server port: ";
    std::cin >> serverPort;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cerr << "Error creating socket.\n";
        return 1;
    }

    sockaddr_in serverAddr;
    std::memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(serverPort);

    if (inet_pton(AF_INET, serverIp.c_str(), &serverAddr.sin_addr) <= 0) {
        std::cerr << "Invalid address or address not supported.\n";
        close(sock);
        return 1;
    }

    if (connect(sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Connection failed.\n";
        close(sock);
        return 1;
    }

    std::cout << "Connected to the bank server at " << serverIp << ":" << serverPort << "\n";
    std::cout << "Enter commands (LOGIN username or OPEN username, then DEPOSIT/WITHDRAW, etc.)\n";

    while (true) {
        std::string userInput;
        if (!std::getline(std::cin, userInput)) {
            break;
        }

        sendLine(sock, userInput);

        std::string fromServer = readLine(sock);
        if (fromServer.empty()) {
            std::cout << "Server closed the connection or read error.\n";
            break;
        }

        std::cout << "Server: " << fromServer << std::endl;
    }

    close(sock);
    return 0;
}
