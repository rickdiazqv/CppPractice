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

WOLFSSL *WolfSSLCreator::create(int sock)
{
    /* Create a WOLFSSL object */
    WOLFSSL *ssl = wolfSSL_new(ctx);

    if (ssl == nullptr)
    {
        LOGW << "failed to create SSL";
        return nullptr;
    }

    /* Attach wolfSSL to the socket */
    if (wolfSSL_set_fd(ssl, sock) != SSL_SUCCESS)
    {
        LOGW << "failed to set client socket";
        return nullptr;
    }

    /* Establish TLS connection */
    if (wolfSSL_accept(ssl) != WOLFSSL_SUCCESS)
    {
        LOGW << "failed to accept SSL";
        return nullptr;
    }

    LOGI << "Client connected successfully\n";

    return ssl;
}