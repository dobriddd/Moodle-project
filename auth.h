#ifndef AUTH_H
#define AUTH_H

#include "user.h"
#include "admin.h"
#include "teacher.h"
#include "student.h"
#include <string>

class Auth {
public:
    static User* login(const std::string& id, const std::string& password);
};

#endif
