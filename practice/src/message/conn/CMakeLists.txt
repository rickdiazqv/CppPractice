# CMakeのバージョンを設定する
cmake_minimum_required(VERSION 3.13.5)

# ライブラリを追加
add_library(conn STATIC messageconnection.cpp)

# インクルードディレクトリを追加
target_include_directories(conn PUBLIC ${MESSAGE_DIR})

# ライブラリディレクトリを追加
target_link_directories(conn PUBLIC ${MESSAGE_DIR})

# ライブラリをリンク
target_link_libraries(conn PUBLIC message)