# CMakeのバージョンを設定する
cmake_minimum_required(VERSION 3.22.1)

# ライブラリを追加
add_library(player STATIC playerdata.cpp)
add_library(plgm STATIC playergamedata.cpp)

# インクルードディレクトリを追加
target_include_directories(
    plgm
    PUBLIC
    ${COMMON_DIR}
)

# ライブラリディレクトリを追加
target_link_directories(
    plgm
    PUBLIC
    ${COMMON_DIR}
)

# ライブラリをリンク
target_link_libraries(
    player
    PUBLIC
    plgm
)
target_link_libraries(
    plgm
    PUBLIC
    common
)