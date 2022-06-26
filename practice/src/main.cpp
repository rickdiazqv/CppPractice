#include "messagemanager.h"

int main()
{
  // 全てのプロセスの終了処理完了後にexitする
  if (signal(SIGINT, [](int sig)
             {
                GameProcessor::instance().term();
                MessageManager::instance().term();
                exit(0); }) == SIG_ERR)
  {
    return -1;
  }

  static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
  static plog::RollingFileAppender<plog::TxtFormatter> fileAppender(LOG_PATH);

  plog::init(plog::debug, &consoleAppender).addAppender(&fileAppender);

  thread proc([]
              { GameProcessor::instance().run(); });

  auto &mgr = MessageManager::instance();

  mgr.init();
  mgr.run();
  LOGI << "exit main";
  GameProcessor::instance().term();

  return 0;
}
