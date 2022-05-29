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
#include <errno.h>

using namespace std;
using json = nlohmann::json;
template <typename _Key, typename _Tp>
using dict = unordered_map<_Key, _Tp>;