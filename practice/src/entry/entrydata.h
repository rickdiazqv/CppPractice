#include "playerdata.h"

class EntryData
{
private:
    static constexpr const char *k_playerName = "playername";
    static constexpr const char *k_state = "state";
    static constexpr const char *msgType_entry = "entry";

private:
    dict<in_addr_t, PlayerData> entries;

public:
    EntryData();
    ~EntryData();

public:
    int entry(json &j, sockaddr_in addr);
    bool isEntry();
};