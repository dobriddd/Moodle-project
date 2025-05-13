#include "message.h"
#include <ctime>
#include <iostream>

Message::Message(const std::string& sender, const std::string& content)
    : sender(sender), content(content), timestamp(std::time(nullptr)) {}

std::string Message::getMessageInfo() const {
    return "From: " + sender + " | Content: " + content + " | Timestamp: " + std::to_string(timestamp);
}
