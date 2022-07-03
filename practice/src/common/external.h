#pragma once
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <string>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <pthread.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <exception>
#include <plog/Init.h>
#include <plog/Log.h>
#include <plog/Formatters/TxtFormatter.h>
#include <plog/Appenders/ColorConsoleAppender.h>
#include <plog/Appenders/RollingFileAppender.h>
#include <unordered_map>
#include <json.hpp>
#include <errno.h>

using json = nlohmann::json;
using jexc = nlohmann::detail::exception;
using sstream = std::stringstream;
using string = std::string;
using mutex = std::mutex;
using cvar = std::condition_variable;
using thread = std::thread;
using exception = std::exception;
template <typename _Tp>
using queue = std::queue<_Tp>;
template <typename _Mutex>
using ulock = std::unique_lock<_Mutex>;
template <typename _Mutex>
using lguard = std::lock_guard<_Mutex>;
template <typename _Tp>
using vector = std::vector<_Tp>;
template <typename _Key, typename _Tp>
using dict = std::unordered_map<_Key, _Tp>;