# CMakeのバージョンを設定する
cmake_minimum_required(VERSION 3.22.1)
message(${CMAKE_CURRENT_SOURCE_DIR})

# ライブラリを追加
add_library(gmproc STATIC gameprocessor.cpp)

# サブディレクトリを追加
#add_subdirectory(player)

# インクルードディレクトリを追加
target_include_directories(
    gmproc
    PUBLIC
    ${COMMON_DIR}
)

# ライブラリディレクトリを追加
target_link_directories(
    gmproc
    PUBLIC
    ${COMMON_DIR}
)

# ライブラリをリンク
target_link_libraries(
    gmproc
    PUBLIC
    common
)