#include "wolfsslreader.h"

WolfSSLReader::WolfSSLReader(WOLFSSL *ssl) : WolfSSLProcessor(ssl),
                                             l_buff(sizeof(buff))
{
}

WolfSSLReader::~WolfSSLReader()
{
}

int WolfSSLReader::init()
{
    return 0;
}

string WolfSSLReader::read()
{
    memset(buff, 0, l_buff);

    if (wolfSSL_read(ssl, buff, l_buff - 1) == -1)
    {
        LOGW << "failed to read";
        return string();
    }

    return string(buff);
}