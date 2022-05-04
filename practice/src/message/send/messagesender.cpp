#include "messagesender.h"

MessageSender::MessageSender(u_short port, sockaddr_in addr, int sock) :
    MessageProcessor(port) {

    this->addr = addr;
    this->sock = sock;
}

MessageSender::~MessageSender() {

}

int MessageSender::init() {
    return 0;
}

void MessageSender::send(const char* const message) {
    LOGI << "send to ";
    sendto(this->sock, message, strlen(message), 0, this->p_addr, this->l_addr);
}