#include "common.h"
#include "playerdata.h"

class EntryData {
private:
    dict<int, PlayerData> entry;

public:
    EntryData();
    ~EntryData();

public:
    int entry(json j);
    bool isEntry();
};