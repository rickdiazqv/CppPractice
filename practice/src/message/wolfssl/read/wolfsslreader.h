#include "wolfsslprocessor.h"

class WolfSSLReader : WolfSSLProcessor
{
public:
    WolfSSLReader(WOLFSSL *ssl);
    ~WolfSSLReader();

public:
    int init() override;

public:
    string read();
    vector<uint8_t> read_bin();
};