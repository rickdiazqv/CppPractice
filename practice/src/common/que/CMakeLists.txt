# CMakeのバージョンを設定する
cmake_minimum_required(VERSION 3.22.1)
message(${CMAKE_CURRENT_SOURCE_DIR})

# ライブラリを追加
#add_library(conn STATIC messageconnection.cpp)

# インクルードディレクトリを追加
#target_include_directories(conn PUBLIC ${COMMON_DIR})

# ライブラリディレクトリを追加
#target_link_directories(conn PUBLIC ${COMMON_DIR})