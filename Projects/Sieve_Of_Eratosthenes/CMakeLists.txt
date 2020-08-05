cmake_minimum_required(VERSION 3.1)

project(Sieve_Of_Eratosthenes
        VERSION 1.0
        DESCRIPTION "Testing the Sieve of Eratosthenes"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src/)

add_executable(App main.cpp)

target_link_libraries(App PRIVATE FUNCTIONS)
target_include_directories(App PRIVATE inc/)