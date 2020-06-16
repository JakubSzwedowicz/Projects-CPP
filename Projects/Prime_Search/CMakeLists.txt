cmake_minimum_required(VERSION 3.1)

set(PROJECT_NAME Finding_the_next_prime)
project(${PROJECT_NAME})


#The other way to build .cpp files
set(SOURCES src/main.cpp src/Functions.cpp)

#Adding the .h file
include_directories(include/)

add_executable(Main ${SOURCES})
