# CMakeのバージョンを設定する
cmake_minimum_required(VERSION 3.16.3)
message(${CMAKE_CURRENT_SOURCE_DIR})

# ライブラリを追加
add_library(entry STATIC entrydata.cpp)

# サブディレクトリを追加
add_subdirectory(player)

# インクルードディレクトリを追加
target_include_directories(
    entry
    PUBLIC
    player
)

# ライブラリディレクトリを追加
target_link_directories(
    entry
    PUBLIC
    player
)

# ライブラリをリンク
target_link_libraries(
    entry
    PUBLIC
    player
)