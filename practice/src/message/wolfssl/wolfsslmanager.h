#pragma once
#include "wolfsslprocessor.h"
#include "wolfsslcreator.h"
#include "wolfsslreader.h"

#define SINGLETON_WOLFSSLMANAGER Singleton<WolfSSLManager>

class WolfSSLManager : public SINGLETON_WOLFSSLMANAGER, public WolfSSLProcessor
{
private:
    static constexpr const char *const SERVER_CERT_PATH = "/etc/ssl/practice/server-cert.pem";
    static constexpr const char *const SERVER_KEY_PATH = "/etc/ssl/practice/server-key.pem";

private:
    WOLFSSL_CTX *ctx = nullptr;

public:
    friend class SINGLETON_WOLFSSLMANAGER;

protected:
    WolfSSLManager();
    virtual ~WolfSSLManager();

public:
    int init() override;
    int term() override;
    int process(int sock, uint8_t buff[]);
};