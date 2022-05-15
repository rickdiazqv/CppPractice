#pragma once
#include "messageprocessor.h"
#include "messageconnection.h"
#include "messagereceiver.h"
#include "messagesender.h"
#include "wolfsslmanager.h"

class MessageManager : public MessageProcessor
{

private:
  WolfSSLManager wolfSSLMgr;

public:
  MessageManager(u_short port);
  ~MessageManager();

public:
  void run();

public:
  int init() override;

private:
  int run_socket();
};