cmake_minimum_required(VERSION 3.20)

project(Hangman LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.8.1
)

FetchContent_MakeAvailable(Catch2)

add_library(hangman_lib
    src/hangman.cpp
)

target_include_directories(
    hangman_lib
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

add_executable(hangman
    src/main.cpp
)

target_link_libraries(
    hangman
    PRIVATE
    hangman_lib
)

enable_testing()

add_executable(hangman_tests
    tests/hangman_tests.cpp
)

target_link_libraries(
    hangman_tests
    PRIVATE
    hangman_lib
    Catch2::Catch2WithMain
)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

include(Catch)

catch_discover_tests(hangman_tests)