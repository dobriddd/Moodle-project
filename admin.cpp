#include "admin.h"
#include <iostream>

Admin::Admin() : User("Admin", "System", 0, "0000") {}

void Admin::createUser(const std::string& firstName, const std::string& lastName, int id, const std::string& password) {
    std::cout << "Created user: " << firstName << " " << lastName << " with ID: " << id << std::endl;
}

void Admin::deleteUser(int id) {
    std::cout << "Deleted user with ID: " << id << std::endl;
}

std::string Admin::getRole() const {
    return "Administrator";
}
