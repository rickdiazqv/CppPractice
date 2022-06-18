#include "entrydata.h"

EntryData::EntryData()
{
}

EntryData::~EntryData()
{
}

int EntryData::entry(json &j, sockaddr_in addr)
{
    if (!json_contains(j, k_msgType, k_message))
    {
        return -1;
    }

    std::string msgType = j[k_msgType].get<std::string>();

    if (msgType != msgType_entry)
    {
        return -2;
    }

    json &mes = j[k_message];

    if (!json_contains(mes, k_playerName, k_state))
    {
        return -3;
    }

    // プレイヤーの登録
    std::string name = mes[k_playerName].get<std::string>();
    in_addr_t ip = addr.sin_addr.s_addr;
    this->entries.emplace(ip, PlayerData(name, ip, addr.sin_port));

    return 0;
}

bool EntryData::isEntry()
{
    return this->entries.size() < PLAYER_NUM;
}