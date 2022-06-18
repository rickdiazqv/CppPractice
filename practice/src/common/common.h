#pragma once
#include "external.h"
#include "manifoldqueue.h"

constexpr const char *LOG_PATH = "message.log";

constexpr u_short PORT = 10049;
constexpr int MESSAGE_SIZE = 1024;

constexpr int PLAYER_NUM = 2;

constexpr const char *k_message = "message";
constexpr const char *k_msgType = "messagetype";

// IPアドレス
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
    std::string getAddr();
};

// JSONキーの存在確認
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

// JSONキーの存在確認
template <typename T, typename... U>
bool json_contains(json &j, T t, U... u)
{
    return json_contains(j, t) && json_contains(j, u...);
}

// 初期化
class Initializer{
public:
    virtual int init() = 0;
    virtual int term() = 0;
};

// Singletonインターフェース
template <typename T>
class Singleton : public Initializer
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

public:
    virtual int init() = 0;
    virtual int term() = 0;

private:
    void operator=(const Singleton &other) {}
    Singleton(const Singleton &other) {}
};