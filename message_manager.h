#ifndef MESSAGE_MANAGER_H
#define MESSAGE_MANAGER_H
#include "message.h"
#include <vector>

class MessageManager {
public:
    static void sendMessage(size_t senderId, size_t recipientId, const std::string& content);
    static std::vector<Message> loadMessages();
};
#endif
