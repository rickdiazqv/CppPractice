# CMakeのバージョンを設定する
cmake_minimum_required(VERSION 3.22.1)
message(${CMAKE_CURRENT_SOURCE_DIR})

# ライブラリを追加
add_library(recv STATIC messagereceiver.cpp)

# インクルードディレクトリを追加
target_include_directories(recv PUBLIC ${MESSAGE_DIR})

# ライブラリディレクトリを追加
target_link_directories(recv PUBLIC ${MESSAGE_DIR})

# ライブラリをリンク
target_link_libraries(recv PUBLIC message)