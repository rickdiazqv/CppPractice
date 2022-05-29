#include "wolfsslprocessor.h"

class WolfSSLReader : WolfSSLProcessor
{
private:
    char buff[MESSAGE_SIZE];
    size_t l_buff;

public:
    WolfSSLReader(WOLFSSL *ssl);
    ~WolfSSLReader();

public:
    int init() override;

public:
    string read();
};