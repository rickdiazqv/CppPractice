#include "entrydata.h"

const string EntryData::k_message = "message";
const string EntryData::k_playername = "playername";
const string EntryData::k_state = "state";

EntryData::EntryData()
{
}

EntryData::~EntryData()
{
}

int EntryData::entry(json &j)
{
    if (!json_contains(j, k_message))
    {
        return -1;
    }

    json &mes = j[k_message];

    if (!json_contains(j, k_playername, k_state))
    {
        return -2;
    }

    return 0;
}

bool EntryData::isEntry()
{
    return this->entries.size() < PLAYER_NUM;
}