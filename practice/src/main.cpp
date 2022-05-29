#include "messagemanager.h"

int main()
{
  auto &mgr = MessageManager::instance();

  mgr.init();
  mgr.run();

  return 0;
}
