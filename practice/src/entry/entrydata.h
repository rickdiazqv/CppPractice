#include "playerdata.h"

class EntryData
{
private:
    static const string k_message;
    static const string k_playername;
    static const string k_state;

private:
    dict<int, PlayerData> entries;

public:
    EntryData();
    ~EntryData();

public:
    int entry(json &j);
    bool isEntry();
};