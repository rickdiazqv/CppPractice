# CMakeのバージョンを設定する
cmake_minimum_required(VERSION 3.13.5)

# プロジェクト名と使用する言語を設定
project(practice CXX)

# 変数を設定
set(MESSAGE_DIR ${CMAKE_SOURCE_DIR}/message)

# 実行ファイルを作成
add_executable(${PROJECT_NAME} main.cpp)

# サブディレクトリを追加
add_subdirectory(common)
add_subdirectory(message)

# インクルードディレクトリを追加
target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${MESSAGE_DIR}
)

# ライブラリディレクトリを追加
target_link_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${MESSAGE_DIR}
)

# ライブラリをリンク
target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    msgmgr
)