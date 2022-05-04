#include "common.h"

IpAddr::IpAddr()
{
}

IpAddr::IpAddr(unsigned int intValue)
{
    this->intValue = intValue;
}

IpAddr::~IpAddr()
{
}

string IpAddr::getAddr()
{
    stringstream ss;

    ss
        << this->charValue[0] << "."
        << this->charValue[1] << "."
        << this->charValue[2] << "."
        << this->charValue[3];

    return ss.str();
}

// bool json_contains(json &j, string k)
//{
//     bool res = j.contains(k);
// }