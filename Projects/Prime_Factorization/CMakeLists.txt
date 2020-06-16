cmake_minimum_required(VERSION 3.1)

set(PROJECT_NAME Prime_Factorization)

project(${PROJECT_NAME})

set(SRC_DIR src/)

add_executable(Main ${SRC_DIR}/main.cpp)

add_library(Fun ${SRC_DIR}/Functions.cpp)
target_link_libraries(Main PUBLIC Fun)

