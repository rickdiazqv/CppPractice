#pragma once
#include <wolfssl/options.h>
#include <wolfssl/ssl.h>
#include <wolfssl/test.h>
#include "common.h"

class WolfSSLProcessor : public Initializer
{
protected:
    WOLFSSL *ssl = nullptr;

public:
    WolfSSLProcessor();
    WolfSSLProcessor(WOLFSSL *ssl);
    ~WolfSSLProcessor();
};