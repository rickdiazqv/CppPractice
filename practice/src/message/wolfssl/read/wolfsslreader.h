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
    std::vector<uint8_t> read_bin();
};