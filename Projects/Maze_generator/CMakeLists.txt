cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME "Maze Generator")

project(${PROJECT_NAME})

set(SOURCES src/main.cpp src/Maze.cpp)

include_directories(include/)


#if(NOT CMAKE_BUILD_TYPE)
#	set(CMAKE_BUILD_TYPE "Release")
#	message(STATUS "Build type not specified: Use Release by default")
#endif(NOT CMAKE_BUILD_TYPE)

#if(CMAKE_BUILD_TYPE EQUAL "DEBUG")
#	message ("Debug mode!")
#	set(EXECUTABLE_NAME "Main-Debug")
#	add_executable(Main-Debug ${SOURCES})
#elseif(CMAKE_BUILD_TYPE EQUAL "Release")
#	message ("Release mode!")
#	set(EXECUTABLE_NAME "Main-Release")
#	add_executable(Main-Release ${SOURCES})
#endif()

add_executable(Main ${SOURCES})
