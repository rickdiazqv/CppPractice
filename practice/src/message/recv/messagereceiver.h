#pragma once
#include "messageprocessor.h"

class MessageReceiver : public MessageProcessor {
public:
    MessageReceiver(u_short port, int sock);
    ~MessageReceiver();

public:
    int init() override;

public:
    string receive();
};