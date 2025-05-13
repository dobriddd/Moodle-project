#ifndef ADMIN_H
#define ADMIN_H
#include "user.h"

class Admin : public User {
public:
    Admin();
    void createUser(const std::string& firstName, const std::string& lastName, int id, const std::string& password);
    void deleteUser(int id);
    std::string getRole() const override;
};

#endif //ADMIN_H
