# CMakeのバージョンを設定する
cmake_minimum_required(VERSION 3.22.1)
message(${CMAKE_CURRENT_SOURCE_DIR})

# プロジェクト名と使用する言語を設定
project(practice CXX)

# 変数を設定
set(COMMON_DIR ${CMAKE_SOURCE_DIR}/common)
set(QUE_DIR ${COMMON_DIR}/que)
set(MESSAGE_DIR ${CMAKE_SOURCE_DIR}/message)
set(WOLFSSL_DIR ${MESSAGE_DIR}/wolfssl)

# 実行ファイルを作成
add_executable(${PROJECT_NAME} main.cpp)

# サブディレクトリを追加
add_subdirectory(common)
add_subdirectory(entry)
add_subdirectory(message)

# インクルードディレクトリを追加
target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${MESSAGE_DIR}
    entry
)

# ライブラリディレクトリを追加
target_link_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${MESSAGE_DIR}
    entry
)

# ライブラリをリンク
target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    msgmgr
    entry
)