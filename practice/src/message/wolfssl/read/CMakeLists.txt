# CMakeのバージョンを設定する
cmake_minimum_required(VERSION 3.16.3)
message(${CMAKE_CURRENT_SOURCE_DIR})

# ライブラリを追加
add_library(sslread STATIC wolfsslreader.cpp)

# インクルードディレクトリを追加
target_include_directories(
    sslread
    PUBLIC
    ${WOLFSSL_DIR}
)

# ライブラリディレクトリを追加
target_link_directories(
    sslread
    PUBLIC
    ${WOLFSSL_DIR}
)

# ライブラリをリンク
target_link_libraries(
    sslread
    PUBLIC
    ssl
)