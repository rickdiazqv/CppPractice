#include "messagemanager.h"

MessageManager::MessageManager() : wolfSSLMgr(WolfSSLManager::instance())
{
  // AF_INETを渡すことによりIPv4で通信する事を指定
  this->addr.sin_family = AF_INET;
  // ポート番号を指定好きなポートを指定してください。
  this->addr.sin_port = htons(PORT);
  // INADDR_ANYを指定する事によりどのIPからでも通信を受け取る状態にする。
  this->addr.sin_addr.s_addr = INADDR_ANY;
}

MessageManager::~MessageManager()
{
}

int MessageManager::init()
{
  static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
  static plog::RollingFileAppender<plog::TxtFormatter> fileAppender(LOG_PATH);

  plog::init(plog::debug, &consoleAppender).addAppender(&fileAppender);

  LOGI << "MessageManager start init";

  wolfSSLMgr.init();

  // ソケットを作成
  this->sock = socket(addr.sin_family, SOCK_STREAM, 0);

  // ソケットの作成に失敗していないかどうか
  if (this->sock < 0)
  {
    LOGI << "failed to create socket";
    return -1;
  }

  // ソケットにアドレスを割り当てる
  if (bind(this->sock, p_addr, l_addr) < 0)
  {
    LOGI << "failed to bind";
    return -1;
  }

  // ソケットを接続待ち状態にする
  if (listen(this->sock, 5) < 0)
  {
    LOGI << "failed to listen";
    return -1;
  }

  LOGI << "MessageManager end init";

  return 0;
}

int MessageManager::term()
{
  return wolfSSLMgr.term();
}

int MessageManager::term(int sock)
{
  // Close the connection to the client
  return term() || close(sock);
}

void MessageManager::run()
{
  while (process() == 0)
  {
  }
}

int MessageManager::process()
{
  int ret = 0;

  // クライアントからの接続を待つ
  MessageConnection conn(this->sock);
  int sockClient = conn.connect();
  if (sockClient < 0)
  {
    LOGI << "failed to connect";
    term(sockClient);

    return -1;
  }
  // デバッグ
  {
    sockaddr_in saddr = conn.getAddr();
    IpAddr ip(saddr.sin_addr.s_addr);
    LOGI << "connected with "
         << ip.getAddr() << ":"
         << saddr.sin_port;
  }

  ret = wolfSSLMgr.process(sockClient) || term(sockClient);

  return ret;

  /*
  // クライアントからデータを受け取る
  MessageReceiver recv(sockClient);
  std::string msg = recv.receive();
  // デバッグ
  {
    sockaddr_in saddr = conn.getAddr();
    IpAddr ip(saddr.sin_addr.s_addr);
    // 受け取った文字を表示
    LOGI << msg << " from";
    LOGI
        << ip.getAddr() << ":"
        << saddr.sin_port;
  }

  // クライアントにデータを送る
  MessageSender send(sockClient);
  send.send("Sent From C++\0");
  // デバッグ
  {
    sockaddr_in saddr = conn.getAddr();
    IpAddr ip(saddr.sin_addr.s_addr);
    LOGI << "sent message to"
         << ip.getAddr() << ":"
         << saddr.sin_port;
  }

  return 0;
  */
}
