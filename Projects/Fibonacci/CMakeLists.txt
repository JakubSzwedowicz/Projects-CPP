cmake_minimum_required(VERSION 3.1)

#Setting the project name variable
set(PROJECT_NAME Fibonacci_functions)

#Setting the project name and version
project(${PROJECT_NAME} VERSION 1.0)

#Enabling C++14
set(CMAKE_CXX_STANDARD 14)

#Setting up the src folder's variable
set(SRC_DIR src/)

#Adding the executable
#add_executable(Fib ${SRC_DIR}/Fib.cpp)
add_executable(Main ${SRC_DIR}/main.cpp)

add_library(Fib ${SRC_DIR}/Fib.cpp)
target_link_libraries(Main PUBLIC Fib)
