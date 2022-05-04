# CMakeのバージョンを設定する
cmake_minimum_required(VERSION 3.13.5)

# ライブラリを追加
add_library(message STATIC messageprocessor.cpp)
add_library(msgmgr STATIC messagemanager.cpp)

# サブディレクトリを追加
add_subdirectory(conn)
add_subdirectory(recv)
add_subdirectory(send)

# インクルードディレクトリを追加
target_include_directories(
    message
    PUBLIC
    ${CMAKE_SOURCE_DIR}/common
)
target_include_directories(
    msgmgr
    PUBLIC
    ${MESSAGE_DIR}/conn
    ${MESSAGE_DIR}/recv
    ${MESSAGE_DIR}/send
)

# ライブラリディレクトリを追加
target_link_directories(
    message
    PUBLIC
    ${CMAKE_SOURCE_DIR}/common
)
target_link_directories(
    msgmgr
    PRIVATE
    ${MESSAGE_DIR}/conn
    ${MESSAGE_DIR}/recv
    ${MESSAGE_DIR}/send
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

# デバッグ
#message(STATUS ${CMAKE_SOURCE_DIR})
#message(STATUS ${CMAKE_BINARY_DIR})