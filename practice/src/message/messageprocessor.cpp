#include "messageprocessor.h"

MessageProcessor::MessageProcessor() :
    p_addr((sockaddr*)&addr),
    l_addr(sizeof(addr)) {

}

MessageProcessor::~MessageProcessor() {

}