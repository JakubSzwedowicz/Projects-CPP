cmake_minimum_required(VERSION 3.1)
set(CMAKE_XCC_STANDARD 20)
project(LIS
        VERSION 1.0
        DESCRIPTION "Project test the algorithm of the longest increasing subsequence"
        LANGUAGES CXX)

include_directories(Inc)

add_executable(App Main.cpp)