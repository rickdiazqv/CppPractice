#include "messagemanager.h"

int main()
{
  MessageManager mgr(PORT);

  mgr.init();
  mgr.run();

  return 0;
}
