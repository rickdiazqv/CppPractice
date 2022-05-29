#pragma once
#include "common.h"

class WolfSSLProcessor
{
protected:
    WOLFSSL *ssl = nullptr;

public:
    WolfSSLProcessor();
    WolfSSLProcessor(WOLFSSL *ssl);
    ~WolfSSLProcessor();

public:
    virtual int init() = 0;
};