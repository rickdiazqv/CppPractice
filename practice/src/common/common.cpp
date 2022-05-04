#include "common.h"

IpAddr::IpAddr() : IpAddr(0)
{
}

IpAddr::IpAddr(const in_addr_t intValue) : intValue(intValue)
{
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