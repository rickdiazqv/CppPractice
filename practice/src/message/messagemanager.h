#pragma once
#include "messageprocessor.h"
#include "messageconnection.h"
#include "messagereceiver.h"
#include "messagesender.h"
#include "wolfsslmanager.h"

#define SINGLETON_MESSAGEMANAGER Singleton<MessageManager>

class MessageManager : public SINGLETON_MESSAGEMANAGER, public MessageProcessor
{

private:
  WolfSSLManager &wolfSSLMgr;

public:
  friend class SINGLETON_MESSAGEMANAGER;

protected:
  MessageManager();
  virtual ~MessageManager();

public:
  void run();

public:
  int init() override;

private:
  int process();
};