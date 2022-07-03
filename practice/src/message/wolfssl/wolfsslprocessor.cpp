#include "wolfsslprocessor.h"

WolfSSLProcessor::WolfSSLProcessor() : WolfSSLProcessor(nullptr)
{
}

WolfSSLProcessor::WolfSSLProcessor(WOLFSSL *ssl) : ssl(ssl)
{
}

WolfSSLProcessor::~WolfSSLProcessor()
{
}