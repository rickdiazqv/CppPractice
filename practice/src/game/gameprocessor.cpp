#include "gameprocessor.h"

GameProcessor::GameProcessor() : running(false), isTermed(false)
{
}

GameProcessor::~GameProcessor()
{
}

int GameProcessor::init()
{
    return 0;
}

int GameProcessor::term()
{
    LOGI << "term Game Processor";
    isTermed = false;
    que.term();

    return 0;
}

void GameProcessor::run()
{
    LOGI << "run Game Processor";

    running = true;
    SocketMessage sockMes;

    while (isTermed)
    {
        LOGI << "getting data";

        if (!que.pop(sockMes))
        {
            LOGW << "failed to pop.";
            return;
        }

        int size = sockMes.buff[0];
        auto begin = std::begin(sockMes.buff);
        auto mes = vector<uint8_t>(begin, begin + size);
        LOGI << "message size: " << mes.size();

        try
        {
            json j = json::from_bson(mes);
            LOGI << sockMes.addr.sin_addr.s_addr;
            LOGI << sockMes.addr.sin_port;
            LOGI << j.dump();
        }
        catch (jexc e)
        {
            LOGW << e.what();
        }
    }

    running = false;
}

int GameProcessor::regist(sockaddr_in addr, uint8_t buff[])
{
    SocketMessage mes;
    mes.addr = addr;

    for (int i = 0; i < MESSAGE_SIZE; i++)
    {
        mes.buff[i] = buff[i];
    }

    que.push(mes);

    return 0;
}