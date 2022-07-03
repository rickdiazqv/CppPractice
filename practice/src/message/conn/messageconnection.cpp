#include "messageconnection.h"

MessageConnection::MessageConnection(int sock)
{
    this->sock = sock;
}

MessageConnection::~MessageConnection()
{
}

int MessageConnection::init()
{
    return 0;
}

int MessageConnection::term()
{
    return 0;
}

int MessageConnection::connect()
{
    LOGI << "wait to connect";
    return accept(this->sock, this->p_addr, (socklen_t *)&(this->l_addr));
}