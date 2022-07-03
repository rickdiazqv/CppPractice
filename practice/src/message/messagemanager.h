#pragma once
#include "messageprocessor.h"
#include "messageconnection.h"
#include "messagereceiver.h"
#include "messagesender.h"
#include "wolfsslmanager.h"
#include "gameprocessor.h"

#define SINGLETON_MESSAGEMANAGER Singleton<MessageManager>

class MessageManager : public SINGLETON_MESSAGEMANAGER, public MessageProcessor
{

private:
  WolfSSLManager &wolfSSLMgr;
  GameProcessor &gameProc;
  int sockClient;

public:
  friend class SINGLETON_MESSAGEMANAGER;

protected:
  MessageManager();
  virtual ~MessageManager();

public:
  void run();

public:
  int init() override;
  int term() override;

private:
  int process();
  int term(int &sock);
};