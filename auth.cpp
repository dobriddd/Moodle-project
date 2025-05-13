#include "auth.h"
#include <iostream>
#include <fstream>

User* Auth::login(const std::string& id, const std::string& password) {
    std::ifstream file("../users.txt");
    std::string firstName, lastName, storedPassword, role;
    int userId;

    if (!file.is_open()) {
        std::cout << "Error: Could not open users file." << std::endl;
        return nullptr;
    }

    while (file >> firstName >> lastName >> userId >> storedPassword >> role) {
        storedPassword.erase(std::remove(storedPassword.begin(), storedPassword.end(), '\n'), storedPassword.end());
        storedPassword.erase(std::remove(storedPassword.begin(), storedPassword.end(), '\r'), storedPassword.end());

        if (std::to_string(userId) == id && storedPassword == password) {
            if (role == "Admin") return new Admin();
            if (role == "Teacher") return new Teacher(firstName, lastName, userId, storedPassword);
            if (role == "Student") return new Student(firstName, lastName, userId, storedPassword);
        }
    }

    std::cout << "Invalid login credentials!" << std::endl;
    return nullptr;
}
