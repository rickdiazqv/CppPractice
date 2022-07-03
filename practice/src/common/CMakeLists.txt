# CMakeのバージョンを設定する
cmake_minimum_required(VERSION 3.22.1)
message(${CMAKE_CURRENT_SOURCE_DIR})

# ライブラリを追加
add_library(common STATIC common.cpp)

# インクルードディレクトリを追加
target_include_directories(common PUBLIC ${QUE_DIR})
target_include_directories(common PUBLIC ${COMMON_DIR})