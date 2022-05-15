#include "wolfsslprocessor.h"
#include "wolfsslcreator.h"

class WolfSSLManager : public WolfSSLProcessor
{
private:
    static constexpr const char *const SERVER_CERT_PATH = "/etc/ssl/practice/server-cert.pem";
    static constexpr const char *const SERVER_KEY_PATH = "/etc/ssl/practice/server-key.pem";

private:
    WOLFSSL_CTX *ctx = nullptr;

public:
    WolfSSLManager();
    ~WolfSSLManager();

public:
    int init() override;
    int run_ssl(int sock);
};