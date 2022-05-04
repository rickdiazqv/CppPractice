#pragma once
#include "common.h"

class MessageProcessor
{
protected:
  sockaddr_in addr;
  sockaddr *const p_addr;
  const int l_addr;
  int sock = 0;

public:
  MessageProcessor();
  ~MessageProcessor();

public:
  virtual int init() = 0;

public:
  sockaddr_in getAddr() const { return this->addr; }
};