#include "user.h"
#include "message.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "message_manager.h"

User::User(const std::string& firstName, const std::string& lastName, int id, const std::string& password)
    : firstName(firstName), lastName(lastName), id(id), password(password) {}

int User::getId() const {
    return id;
}

bool User::checkPassword(const std::string& pwd) const {
    return password == pwd;
}

void User::sendMessage(size_t recipientId, const std::string& content) {
    MessageManager::sendMessage(id, recipientId, content);
    std::cout << "Message sent from user ID " << id << " to user ID " << recipientId << std::endl;
}

void User::viewInbox() const {
    auto messages = MessageManager::loadMessages();
    bool hasMessages = false;
    for (const auto& msg : messages) {
        if (msg.getRecipientId() == id) {
            std::cout << msg.getMessageInfo() << std::endl;
            hasMessages = true;
        }
    }
    if (!hasMessages) {
        std::cout << "Your inbox is empty." << std::endl;
    }
}
void User::deleteMessage(int index) {
    if (index >= 0 && index < static_cast<int>(inbox.size())) {
        inbox.erase(inbox.begin() + index);
    } else {
        std::cout << "Invalid message index!" << std::endl;
    }
}
