#include "message_manager.h"
#include <fstream>
#include <iostream>

void MessageManager::sendMessage(int senderId, int recipientId, const std::string& content) {
    std::ofstream file("../messages.txt", std::ios::app);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open messages.txt for writing!" << std::endl;
        return;
    }

    file << senderId << " " << recipientId << " " << content << std::endl;
    file.close();
    std::cout << "Message sent successfully!" << std::endl;
}

void MessageManager::saveMessage(const Message& msg) {
    std::ofstream file("../messages.txt", std::ios::app);
    file << msg.getMessageInfo() << std::endl;
    file.close();
}

std::vector<Message> MessageManager::loadMessages() {
    std::vector<Message> messages;
    std::ifstream file("../messages.txt");
    std::string line;

    while (getline(file, line)) {
        messages.push_back(Message("System", line));
    }

    return messages;
}
