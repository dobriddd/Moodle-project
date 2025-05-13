#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "message.h"

class User {
protected:
    std::string firstName;
    std::string lastName;
    int id;
    std::string password;
    std::vector<Message> inbox;

public:
    User(const std::string& firstName, const std::string& lastName, int id, const std::string& password);
    virtual ~User() = default;

    int getId() const;
    bool checkPassword(const std::string& pwd) const;

    virtual void sendMessage(int recipientId, const std::string& content);
    virtual void viewInbox() const;
    virtual void deleteMessage(int index);
    virtual std::string getRole() const = 0;
};

#endif