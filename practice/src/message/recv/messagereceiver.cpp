#include "messagereceiver.h"

MessageReceiver::MessageReceiver(u_short port, int sock) :
    MessageProcessor(port) {
    
    this->sock = sock;
}

MessageReceiver::~MessageReceiver() {

}

int MessageReceiver::init() {
    return 0;
}

string MessageReceiver::receive() {
    char rcvbuf[MESSAGE_SIZE];

    memset(rcvbuf, 0, MESSAGE_SIZE);
    recvfrom(this->sock, rcvbuf, MESSAGE_SIZE, 0, this->p_addr, (socklen_t *)&(this->l_addr));

    return string(rcvbuf);
}