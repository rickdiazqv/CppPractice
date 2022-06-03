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

vector<uint8_t> WolfSSLReader::read_bin()
{
    uint8_t buff[MESSAGE_SIZE];
    memset(buff, 0, MESSAGE_SIZE);

    if (wolfSSL_read(ssl, buff, MESSAGE_SIZE) == -1)
    {
        LOGW << "failed to read as bin";
        return vector<uint8_t>();
    }

    return vector<uint8_t>(std::begin(buff), std::end(buff));
}