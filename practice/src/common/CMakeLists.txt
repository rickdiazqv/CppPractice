# CMakeのバージョンを設定する
cmake_minimum_required(VERSION 3.16.3)
message(${CMAKE_CURRENT_SOURCE_DIR})

# ライブラリを追加
add_library(common STATIC common.cpp)

# ライブラリをリンク
target_link_libraries(
    common
    PRIVATE
    wolfssl
)