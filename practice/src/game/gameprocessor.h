#include "common.h"

#define SINGLETON_GAMEPROCESSOR Singleton<GameProcessor>

class GameProcessor : public SINGLETON_GAMEPROCESSOR
{
public:
    friend class SINGLETON_GAMEPROCESSOR;

private:
    ManifoldQueue<SocketMessage> que;
    bool running;
    bool isTermed;

protected:
    GameProcessor();
    virtual ~GameProcessor();

public:
    int init() override;
    int term() override;

public:
    void run();
    int regist(sockaddr_in addr, uint8_t buff[]);
    bool isRunning() { return running; }
};