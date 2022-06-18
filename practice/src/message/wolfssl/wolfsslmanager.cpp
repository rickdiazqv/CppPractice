#include "wolfsslmanager.h"

WolfSSLManager::WolfSSLManager()
{
}

WolfSSLManager::~WolfSSLManager()
{
}

int WolfSSLManager::init()
{
    int ret;
    char error[MESSAGE_SIZE];

    // SSLライブラリの初期化
    if (wolfSSL_Init() != SSL_SUCCESS)
    {
        LOGE << "wolfssl init error";
        return -1;
    }

    // Get encryption method
    // Create wolfSSL_CTX
    if ((ctx = wolfSSL_CTX_new(wolfTLSv1_2_server_method())) == nullptr)
    {
        LOGE << "ctx error";
        return -1;
    }

    //  Load server certs into ctx
    if ((ret = wolfSSL_CTX_use_certificate_file(ctx, SERVER_CERT_PATH, SSL_FILETYPE_PEM)) != SSL_SUCCESS)
    {
        LOGE << "cert error: " << ret;
        return -1;
    }

    // Load server key into ctx
    if ((ret = wolfSSL_CTX_use_PrivateKey_file(ctx, SERVER_KEY_PATH, SSL_FILETYPE_PEM)) != SSL_SUCCESS)
    {
        LOGE << "key error: " << ret;
        return -1;
    }

    return 0;
}

int WolfSSLManager::term()
{
    // Notify the client that the connection is ending
    wolfSSL_shutdown(ssl);
    LOGI << "Shutdown complete";

    // Free the wolfSSL object
    wolfSSL_free(ssl);

    return 0;
}

int WolfSSLManager::process(int sock)
{
    WolfSSLCreator cre(ctx);
    WOLFSSL *ssl = cre.create(sock);

    if (ssl == nullptr)
    {
        return -1;
    }

    WolfSSLReader read(ssl);
    auto mes = read.read_bin();
    int size = mes[0];
    mes = std::vector<uint8_t>(mes.begin(), mes.begin() + size);

    try
    {
        json j = json::from_bson(mes);
        LOGI << j.dump();
    }
    catch (jexc e)
    {
        LOGW << e.what();
    }

    return 0;
}