# CMakeのバージョンを設定する
cmake_minimum_required(VERSION 3.22.1)
message(${CMAKE_CURRENT_SOURCE_DIR})

# ライブラリを追加
add_library(ssl STATIC wolfsslprocessor.cpp)
add_library(sslmgr STATIC wolfsslmanager.cpp)

# サブディレクトリを追加
add_subdirectory(cre)
add_subdirectory(read)

# インクルードディレクトリを追加
target_include_directories(
    ssl
    PUBLIC
    ${COMMON_DIR}
)
target_include_directories(
    sslmgr
    PUBLIC
    ${WOLFSSL_DIR}/cre
    ${WOLFSSL_DIR}/read
)

# ライブラリディレクトリを追加
target_link_directories(
    ssl
    PUBLIC
    ${COMMON_DIR}
)
target_link_directories(
    sslmgr
    PRIVATE
    ${WOLFSSL_DIR}/cre
    ${WOLFSSL_DIR}/read
)

# ライブラリをリンク
target_link_libraries(
    ssl
    PRIVATE
    wolfssl
)
target_link_libraries(
    ssl
    PUBLIC
    common
)
target_link_libraries(
    sslmgr
    PUBLIC
    ssl
)
target_link_libraries(
    sslmgr
    PRIVATE
    sslcre
    sslread
)