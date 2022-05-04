#pragma once
#include <sys/types.h>
#include <netinet/in.h>
#include "common.h"

class MessageProcessor {
protected:
  const int port;
  sockaddr_in addr;
  sockaddr* const p_addr;
  const int l_addr;
  int sock = 0;

public:
  MessageProcessor(u_short port);
  ~MessageProcessor();

public:
  virtual int init() = 0;

public:
  sockaddr_in getAddr() const { return this->addr; }
};