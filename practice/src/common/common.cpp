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

std::string IpAddr::getAddr()
{
    std::stringstream ss;

    ss
        << (in_addr_t)(this->charValue[0]) << "."
        << (in_addr_t)(this->charValue[1]) << "."
        << (in_addr_t)(this->charValue[2]) << "."
        << (in_addr_t)(this->charValue[3]);

    return ss.str();
}