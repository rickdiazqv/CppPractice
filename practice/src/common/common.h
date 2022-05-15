#pragma once
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/types.h>
#include <netinet/in.h>
#include <plog/Init.h>
#include <plog/Log.h>
#include <plog/Formatters/TxtFormatter.h>
#include <plog/Appenders/ColorConsoleAppender.h>
#include <plog/Appenders/RollingFileAppender.h>
#include <unordered_map>
#include <json.hpp>
#include <wolfssl/options.h>
#include <wolfssl/ssl.h>
#include <wolfssl/test.h>
#include <errno.h>

using namespace std;
using json = nlohmann::json;
template <typename _Key, typename _Tp>
using dict = unordered_map<_Key, _Tp>;

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