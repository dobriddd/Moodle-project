#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include <string>

class UserManager {
public:
    static void addUser(const std::string& firstName, const std::string& lastName, int id, const std::string& password, const std::string& role);
    static bool userExists(int id);
};

#endif
