#pragma once
#include "external.h"
#include "manifoldqueue.h"

constexpr const char *LOG_PATH = "message.log";

constexpr u_short PORT = 1919;
constexpr int MESSAGE_SIZE = 1024;

constexpr int PLAYER_NUM = 2;

constexpr const char *k_message = "message";
constexpr const char *k_msgType = "messagetype";

union IpAddr
{
public:
    in_addr_t intValue;
    uint8_t charValue[4];

public:
    IpAddr();
    IpAddr(const in_addr_t intValue);
    ~IpAddr();

public:
    string getAddr();
};

template <typename T>
bool json_contains(json &j, T t)
{
    bool res = j.contains(t);

    if (!res)
    {
        LOGW << t << " is not found";
    }

    return res;
}

template <typename T, typename... U>
bool json_contains(json &j, T t, U... u)
{
    return json_contains(j, t) && json_contains(j, u...);
}

template <typename T>
class Singleton
{
protected:
    Singleton() {}
    virtual ~Singleton() {}

public:
    static inline T &instance()
    {
        static T ins;
        return ins;
    }

private:
    void operator=(const Singleton &other) {}
    Singleton(const Singleton &other) {}
};