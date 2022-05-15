#pragma once
#include "common.h"

class WolfSSLProcessor
{
private:
    WOLFSSL *ssl = nullptr;

public:
    WolfSSLProcessor();
    WolfSSLProcessor(WOLFSSL *ssl);
    ~WolfSSLProcessor();

public:
    virtual int init() = 0;
};