#include "messageprocessor.h"

MessageProcessor::MessageProcessor(u_short port) :
    port(port),
    p_addr((sockaddr*)&addr),
    l_addr(sizeof(addr)) {

}

MessageProcessor::~MessageProcessor() {

}