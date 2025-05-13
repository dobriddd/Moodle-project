#ifndef MESSAGE_MANAGER_H
#define MESSAGE_MANAGER_H
#include "message.h"
#include <vector>

class MessageManager {
public:
    static void sendMessage(int senderId, int recipientId, const std::string& content);
    static void saveMessage(const Message& msg);
    static std::vector<Message> loadMessages();
};
#endif
