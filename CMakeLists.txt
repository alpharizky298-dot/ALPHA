cmake_minimum_required(VERSION 3.20)

project(ALPHA
    VERSION 0.1.0
    DESCRIPTION "ALPHA Proof-of-Work blockchain"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# =========================
# ALPHA CORE
# =========================

add_library(alpha_core

    src/crypto/hash.cpp

    src/block/block.cpp

    src/consensus/pow.cpp
)

target_include_directories(alpha_core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# =========================
# ALPHA NODE
# =========================

add_executable(alpha_node

    src/main.cpp
)

target_link_libraries(alpha_node
    PRIVATE
        alpha_core
)

# =========================
# TESTING
# =========================

enable_testing()

# Crypto test
add_executable(hash_test
    tests/crypto/hash_test.cpp
)

target_link_libraries(hash_test
    PRIVATE
        alpha_core
)

add_test(
    NAME hash_test
    COMMAND hash_test
)

# Block test
add_executable(block_test
    tests/block/block_test.cpp
)

target_link_libraries(block_test
    PRIVATE
        alpha_core
)

add_test(
    NAME block_test
    COMMAND block_test
)

# Proof-of-Work test
add_executable(pow_test
    tests/consensus/pow_test.cpp
)

target_link_libraries(pow_test
    PRIVATE
        alpha_core
)

add_test(
    NAME pow_test
    COMMAND pow_test
)
