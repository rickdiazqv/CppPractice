# CMakeのバージョンを設定する
cmake_minimum_required(VERSION 3.22.1)
message(${CMAKE_CURRENT_SOURCE_DIR})

# ライブラリを追加
add_library(send STATIC messagesender.cpp)

# インクルードディレクトリを追加
target_include_directories(send PUBLIC ${MESSAGE_DIR})

# ライブラリディレクトリを追加
target_link_directories(send PUBLIC ${MESSAGE_DIR})

# ライブラリをリンク
target_link_libraries(send PUBLIC message)