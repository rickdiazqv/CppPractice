#include "messagemanager.h"

MessageManager::MessageManager(u_short port) : MessageProcessor(port) {

}

MessageManager::~MessageManager() {

}

int MessageManager::init() {
  static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
  static plog::RollingFileAppender<plog::TxtFormatter> fileAppender(LOG_PATH);
  
  plog::init(plog::debug, &consoleAppender).addAppender(&fileAppender);

  LOGI << "MessageManager start init";

  // AF_INETを渡すことによりIPv4で通信する事を指定
  this->addr.sin_family = AF_INET;
  // ポート番号を指定好きなポートを指定してください。
  this->addr.sin_port = htons(PORT);
  // INADDR_ANYを指定する事によりどのIPからでも通信を受け取る状態にする。
  this->addr.sin_addr.s_addr = INADDR_ANY;

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

void MessageManager::run() {
  while (run_socket() == 0) {
    
  }
}

int MessageManager::run_socket() {
  // クライアントからの接続を待つ
  MessageConnection conn(this->port, this->sock);
  int sockClient = conn.connect();
  if (sockClient < 0) {
    LOGI << "failed to connect";

    return -1;
  }
  LOGI << "connected";

  // クライアントからデータを受け取る  
  MessageReceiver recv(this->port, sockClient);
  string msg = recv.receive();
  // 受け取った文字を表示
  LOGI << msg;

  // クライアントにデータを送る
  MessageSender send(this->port, this->addr, sockClient);
  send.send("Sent From C++\0");

  return 0;
}
