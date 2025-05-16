#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <ctime>

class Message {
    size_t senderId;
    size_t recipientId;
    std::string content;
    std::string timestamp;

public:
    Message(size_t senderId, size_t recipientId, const std::string& content);
    int getRecipientId() const;
    std::string getMessageInfo() const;
};

#endif
