#pragma once
#include "messageprocessor.h"

class MessageReceiver : public MessageProcessor
{
public:
    MessageReceiver(int sock);
    ~MessageReceiver();

public:
    int init() override;

public:
    std::string receive();
};