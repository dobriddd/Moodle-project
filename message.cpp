#include "message.h"
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>

std::string getCurrentTimestamp() {
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);
    std::ostringstream oss;
    oss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}
Message::Message(size_t senderId, size_t recipientId, const std::string& content)
    : senderId(senderId), recipientId(recipientId), content(content), timestamp(getCurrentTimestamp()) {}
int Message::getRecipientId() const {
    return recipientId;
}
std::string Message::getMessageInfo() const {
    return std::to_string(senderId) + " " + std::to_string(recipientId) + " " + timestamp + " " + content;
}
