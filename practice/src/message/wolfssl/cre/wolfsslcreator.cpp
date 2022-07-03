#include "wolfsslcreator.h"

WolfSSLCreator::WolfSSLCreator(WOLFSSL_CTX *ctx) : ctx(ctx)
{
}

WolfSSLCreator::~WolfSSLCreator()
{
}

int WolfSSLCreator::init()
{
    return 0;
}

int WolfSSLCreator::term()
{
    return 0;
}

WOLFSSL *WolfSSLCreator::create(int sock)
{
    /* Create a WOLFSSL object */
    WOLFSSL *ssl = wolfSSL_new(ctx);
    int ret;
    char error[MESSAGE_SIZE];

    if (ssl == nullptr)
    {
        LOGE << "failed to create SSL";
        return nullptr;
    }

    /* Attach wolfSSL to the socket */
    if ((ret = wolfSSL_set_fd(ssl, sock)) != SSL_SUCCESS)
    {
        LOGE << "failed to set client socket: " << ret;
        LOGE << wolfSSL_ERR_error_string(wolfSSL_get_error(ssl, ret), error);
        return nullptr;
    }

    /* Establish TLS connection */
    if ((ret = wolfSSL_accept(ssl)) != WOLFSSL_SUCCESS)
    {
        LOGE << "failed to accept: " << ret;
        LOGE << wolfSSL_ERR_error_string(wolfSSL_get_error(ssl, ret), error);
        return nullptr;
    }

    LOGI << "Client connected successfully\n";

    return ssl;
}