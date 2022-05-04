#pragma once
#include "messageprocessor.h"

class MessageConnection : public MessageProcessor {
public:
    MessageConnection(int sock);
    ~MessageConnection();

public:
    int init() override;

public:
    int connect();
};