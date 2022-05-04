#pragma once
#include "messageprocessor.h"

class MessageConnection : public MessageProcessor {
public:
    MessageConnection(u_short port, int sock);
    ~MessageConnection();

public:
    int init() override;

public:
    int connect();
};