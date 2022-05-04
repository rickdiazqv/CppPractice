#pragma once
#include "messageprocessor.h"

class MessageSender : MessageProcessor {
public:
    MessageSender(u_short port, sockaddr_in addr, int sock);
    ~MessageSender();

public:
    int init() override;

public:
    void send(const char* const message);
};