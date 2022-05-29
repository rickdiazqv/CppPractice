#pragma once
#include "wolfsslprocessor.h"

class WolfSSLCreator : public WolfSSLProcessor
{
private:
    WOLFSSL_CTX *const ctx = nullptr;

public:
    WolfSSLCreator(WOLFSSL_CTX *ctx);
    ~WolfSSLCreator();

public:
    int init() override;

public:
    WOLFSSL *create(int sock);
};