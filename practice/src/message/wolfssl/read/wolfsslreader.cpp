#include "wolfsslreader.h"

WolfSSLReader::WolfSSLReader(WOLFSSL *ssl) : WolfSSLProcessor(ssl)
{
}

WolfSSLReader::~WolfSSLReader()
{
}

int WolfSSLReader::init()
{
    return 0;
}

int WolfSSLReader::term()
{
    return 0;
}

string WolfSSLReader::read()
{
    char buff[MESSAGE_SIZE];
    memset(buff, 0, MESSAGE_SIZE);

    if (wolfSSL_read(ssl, buff, MESSAGE_SIZE) == -1)
    {
        LOGW << "failed to read";
        return string();
    }

    return string(buff);
}

int WolfSSLReader::read_bin(uint8_t buff[])
{
    memset(buff, 0, MESSAGE_SIZE);

    if (wolfSSL_read(ssl, buff, MESSAGE_SIZE) == -1)
    {
        LOGW << "failed to read as bin";
        return -1;
    }

    return 0;
}