#include "wolfsslprocessor.h"

class WolfSSLReader : WolfSSLProcessor
{
public:
    WolfSSLReader(WOLFSSL *ssl);
    ~WolfSSLReader();

public:
    int init() override;
    int term() override;

public:
    std::string read();
    int read_bin(uint8_t buff[]);
};