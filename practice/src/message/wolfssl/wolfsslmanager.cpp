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
    wolfSSL_Init();

    // Get encryption method
    // Create wolfSSL_CTX
    if ((ctx = wolfSSL_CTX_new(wolfTLSv1_2_server_method())) == nullptr)
    {
        LOGE << "ctx error";
        return -1;
    }

    /*if (wolfSSL_CTX_load_verify_locations(ctx, "/etc/ssl/practiceCA/ca-cert.pem", 0) != SSL_SUCCESS)
    {
        LOGE << "ca cert error: " << res;
        return -1;
    }*/

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
    mes = vector<uint8_t>(mes.begin(), mes.begin() + size);

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