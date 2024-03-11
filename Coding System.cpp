
#include <iostream>
#include <unordered_map>
#include <string>

// User database (in-memory for simplicity)
std::unordered_map<std::string, std::string> users = {
    {"user1", "password1"},
    {"user2", "password2"}
};

// Autocorrect error codes
std::unordered_map<std::string, std::string> errorCodes = {
    {"8n", "Syntax error: missing semicolon"}
};

// Function to authenticate user
bool authenticateUser(const std::string& username, const std::string& password) {
    auto it = users.find(username);
    if (it != users.end() && it->second == password) {
        return true;}
    return false;
}

// Function to autocorrect error code
std::string autocorrectErrorCode(const std::string& errorCode) {
    auto it = errorCodes.find(errorCode);
    if (it != errorCodes.end()) {
        return it->second;
    }
    return "Error code not found";
}

int main() {
    // User login
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (authenticateUser(username, password)) {std::cout << "Login successful" << std::endl;

        // Autocorrect error code
        std::string errorCode;
        std::cout << "Enter error code: ";
        std::cin >> errorCode;

        std::string correctedCode = autocorrectErrorCode(errorCode);
        std::cout << "Corrected code: " << correctedCode << std::endl;
    }
    else {
        std::cout << "Invalid credentials" << std::endl;
    }

    return 0;
}