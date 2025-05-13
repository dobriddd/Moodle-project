#include "user_manager.h"
#include <fstream>
#include <iostream>

void UserManager::addUser(const std::string& firstName, const std::string& lastName, int id, const std::string& password, const std::string& role) {
    std::ofstream file("../users.txt", std::ios::app);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file for writing!" << std::endl;
        return;
    }

    file << firstName << " " << lastName << " " << id << " " << password << " " << role << "\n";
    file.close();
    std::cout << "User added successfully!" << std::endl;
}

bool UserManager::userExists(int id) {
    std::ifstream file("../users.txt");
    std::string firstName, lastName, password, role;
    int userId;

    while (file >> firstName >> lastName >> userId >> password >> role) {
        if (userId == id) return true;
    }

    return false;
}