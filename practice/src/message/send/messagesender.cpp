#include "messagesender.h"

MessageSender::MessageSender(int sock)
{
    this->sock = sock;
}

MessageSender::~MessageSender()
{
}

int MessageSender::init()
{
    return 0;
}

void MessageSender::send(const char *const message)
{
    sendto(this->sock, message, strlen(message), 0, this->p_addr, this->l_addr);
}