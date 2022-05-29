# CMakeのバージョンを設定する
cmake_minimum_required(VERSION 3.16.3)
message(${CMAKE_CURRENT_SOURCE_DIR})

# ライブラリを追加
add_library(message STATIC messageprocessor.cpp)
add_library(msgmgr STATIC messagemanager.cpp)

# サブディレクトリを追加
add_subdirectory(conn)
add_subdirectory(recv)
add_subdirectory(send)
add_subdirectory(wolfssl)

# インクルードディレクトリを追加
target_include_directories(
    message
    PUBLIC
    ${COMMON_DIR}
)
target_include_directories(
    msgmgr
    PUBLIC
    ${MESSAGE_DIR}/recv
    ${MESSAGE_DIR}/conn
    ${MESSAGE_DIR}/send
    ${WOLFSSL_DIR}
)

# ライブラリディレクトリを追加
target_link_directories(
    message
    PUBLIC
    ${COMMON_DIR}
)
target_link_directories(
    msgmgr
    PRIVATE
    ${MESSAGE_DIR}/conn
    ${MESSAGE_DIR}/recv
    ${MESSAGE_DIR}/send
    ${WOLFSSL_DIR}
)

# ライブラリをリンク
target_link_libraries(
    message
    PUBLIC
    common
)
target_link_libraries(
    msgmgr
    PUBLIC
    message
)
target_link_libraries(
    msgmgr
    PRIVATE
    conn
    recv
    send
)
target_link_libraries(
    msgmgr
    PUBLIC
    sslmgr
)