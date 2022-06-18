#include "playergamedata.h"

class PlayerData
{
private:
    const IpAddr addr;
    const in_port_t port;
    std::string name;
    PlayerGameData gameData;

public:
    PlayerData(std::string name, in_addr_t addr, in_port_t port);
    PlayerData(const PlayerData &other);
    ~PlayerData();

public:
    const PlayerData &operator=(const PlayerData &other)
    {
        return *this;
    }
};