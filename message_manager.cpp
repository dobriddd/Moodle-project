#include "message_manager.h"
#include <fstream>
#include <iostream>
#include <sstream>

void MessageManager::sendMessage(size_t senderId, size_t recipientId, const std::string& content) {
    std::ofstream file("../messages.txt", std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open messages.txt for writing!" << std::endl;
        return;
    }

    Message msg(senderId, recipientId, content);
    file << msg.getMessageInfo() << std::endl;
    file.close();
    std::cout << "Message sent successfully!" << std::endl;
}

std::vector<Message> MessageManager::loadMessages() {std::vector<Message> messages;
    std::ifstream file("../messages.txt");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open messages.txt!" << std::endl;
        return messages;
    }

    size_t senderId, recipientId;
    std::string timestamp, content, line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        if (!(iss >> senderId >> recipientId >> std::ws)) {
            std::cerr << "Error: Invalid message format!" << std::endl;
            continue;
        }
        std::getline(iss, timestamp, ' ');

        std::getline(iss, content);

        messages.emplace_back(senderId, recipientId, content);
    }

    file.close();
    return messages;
}
