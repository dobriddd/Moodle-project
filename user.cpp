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

void User::sendMessage(int recipientId, const std::string& content) {
    MessageManager::sendMessage(id, recipientId, content);
    std::cout << "Message sent from user ID " << id << " to user ID " << recipientId << std::endl;
}

void User::viewInbox() const {
    std::ifstream file("../messages.txt");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open messages.txt for reading!" << std::endl;
        return;
    }

    std::string line;
    std::cout << "Inbox for user ID " << id << ":\n";
    bool hasMessages = false;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int senderId, recipientId;
        std::string content;
        iss >> senderId >> recipientId;
        std::getline(iss, content);

        if (recipientId == id) {
            std::cout << "From User ID " << senderId << ": " << content << std::endl;
            hasMessages = true;
        }
    }

    if (!hasMessages) {
        std::cout << "No messages in your inbox.\n";
    }

    file.close();
}

void User::deleteMessage(int index) {
    if (index >= 0 && index < static_cast<int>(inbox.size())) {
        inbox.erase(inbox.begin() + index);
    } else {
        std::cout << "Invalid message index!" << std::endl;
    }
}
