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

void MessageManager::run()
{
  while (run_socket() == 0)
  {
  }
}

int MessageManager::run_socket()
{
  WOLFSSL_CTX *ctx;
  WOLFSSL *ssl;
  int res;

  // クライアントからの接続を待つ
  MessageConnection conn(this->sock);
  int sockClient = conn.connect();
  if (sockClient < 0)
  {
    LOGI << "failed to connect";

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

  wolfSSLMgr.run_ssl(sockClient);
  return 0;

  /*int sockListen, sockClient;
  sockaddr addrClient;
  socklen_t l_addrClient = sizeof(addrClient);
  tcp_accept(&this->sock, &sockClient, nullptr, PORT, 1, 0, 0, 0, 1,
             (SOCKADDR_IN_T *)&addrClient, &l_addrClient);

  // Create wolfSSL object
  if ((ssl = wolfSSL_new(ctx)) == nullptr)
  {
    LOGE << "ssl error";
    return -1;
  }

  int sockcl = sockClient;
  if ((res = wolfSSL_set_fd(ssl, sockcl)) != SSL_SUCCESS)
  {
    LOGE << "set error: " << res;
    return -1;
  }
  LOGI << "sockcl: " << sockcl;

  int n;
  char buf[MESSAGE_SIZE];
  if ((n = wolfSSL_read(ssl, buf, (sizeof(buf) - 1))) > 0)
  {
    if (wolfSSL_write(ssl, buf, n) != n)
      LOGE << "wolfSSL_write error";
  }
  LOGI << buf;
  stringstream ss;
  for (int i = 0; i < 12; i++)
  {
    ss << (int)buf[i] << " ";
  }
  LOGI << ss.str();
  if (n < 0)
    LOGE << "wolfSSL_read error = " << wolfSSL_get_error(ssl, n) << ", n = " << n;
  else if (n == 0)
    LOGI << "Connection close by peer";
  wolfSSL_free(ssl);
  close(sockcl);
  wolfSSL_CTX_free(ctx);
  wolfSSL_Cleanup();
  // exit(EXIT_SUCCESS);
  return 0;*/

  // クライアントからデータを受け取る
  MessageReceiver recv(sockClient);
  string msg = recv.receive();
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
}
