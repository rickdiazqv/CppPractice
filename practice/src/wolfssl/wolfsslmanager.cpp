#include "wolfsslmanager.h"

WolfSSLManager::WolfSSLManager()
{
}

WolfSSLManager::~WolfSSLManager()
{
}

int WolfSSLManager::init()
{
    int res;

    // SSLライブラリの初期化
    wolfSSL_Init();

    // Get encryption method
    // Create wolfSSL_CTX
    if ((ctx = wolfSSL_CTX_new(wolfTLSv1_2_server_method())) == nullptr)
    {
        LOGE << "ctx error";
        return -1;
    }

    //  Load server certs into ctx
    if ((res = wolfSSL_CTX_use_certificate_file(ctx, SERVER_CERT_PATH, SSL_FILETYPE_PEM)) != SSL_SUCCESS)
    {
        LOGE << "cert error" << res;
        return -1;
    }

    // Load server key into ctx
    if ((res = wolfSSL_CTX_use_PrivateKey_file(ctx, SERVER_KEY_PATH, SSL_FILETYPE_PEM)) != SSL_SUCCESS)
    {
        LOGE << "key error: " << res;
        return -1;
    }
}

int WolfSSLManager::run_ssl(int sock)
{
    WolfSSLCreator cre(ctx);
    WOLFSSL *ssl = cre.create(sock);

    if (ssl == nullptr)
    {
        return -1;
    }
}