#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <ctime>

class Message {
    std::string sender;
    std::string content;
    std::time_t timestamp;

public:
    Message(const std::string& sender, const std::string& content);
    std::string getMessageInfo() const;
};

#endif
