#pragma once
#include "messageprocessor.h"

class MessageSender : MessageProcessor
{
public:
    MessageSender(int sock);
    ~MessageSender();

public:
    int init() override;

public:
    void send(const char *const message);
};