# CMakeのバージョンを設定する
cmake_minimum_required(VERSION 3.13.5)

# ライブラリを追加
add_library(common STATIC common.cpp)

# ライブラリをリンク
target_link_libraries(
    common
    PUBLIC
    wolfssl
)