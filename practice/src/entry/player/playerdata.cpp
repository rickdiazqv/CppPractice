#include "playerdata.h"

PlayerData::PlayerData(std::string name, in_addr_t addr, in_port_t port) : name(name),
                                                                      addr(addr),
                                                                      port(port)
{
}

PlayerData::PlayerData(const PlayerData &other) : PlayerData(other.name, other.addr.intValue, other.port)
{
}

PlayerData::~PlayerData()
{
}