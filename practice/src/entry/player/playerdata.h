#include "playergamedata.h"

class PlayerData
{
private:
    IpAddr addr;
    in_port_t port;
    PlayerGameData gameData;

public:
    PlayerData();
    ~PlayerData();
};