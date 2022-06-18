#include "messagereceiver.h"

MessageReceiver::MessageReceiver(int sock)
{
    this->sock = sock;
}

MessageReceiver::~MessageReceiver()
{
}

int MessageReceiver::init()
{
    return 0;
}

std::string MessageReceiver::receive()
{
    char rcvbuf[MESSAGE_SIZE];

    memset(rcvbuf, 0, MESSAGE_SIZE);
    recvfrom(this->sock, rcvbuf, MESSAGE_SIZE, 0, this->p_addr, (socklen_t *)&(this->l_addr));

    return std::string(rcvbuf);
}