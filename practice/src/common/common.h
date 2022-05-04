#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
//#include <unistd.h>
//#include <arpa/inet.h>
//#include <sys/socket.h>
#include <plog/Init.h>
#include <plog/Log.h>
#include <plog/Formatters/TxtFormatter.h>
#include <plog/Appenders/ColorConsoleAppender.h>
#include <plog/Appenders/RollingFileAppender.h>
#include <json.hpp>
#include <unordered_map>

using namespace std;
using json = nlohmann::json;
template<typename _Key, typename _Tp>
using dict = unordered_map<_Key, _Tp>;

constexpr const char* LOG_PATH = "message.log";
constexpr u_short PORT = 1919;
constexpr int MESSAGE_SIZE = 1024;

union IpAddr {
    IpAddr(unsigned int intValue);

    unsigned int intValue;
    unsigned char charValue[4];
};