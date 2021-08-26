cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wmissing-braces -Wshadow \
                    -Wdouble-promotion -Wundef -fno-common \
                    -Wstack-exhausted -Wconversion")

set(PROJECT_NAME "Design Patterns")

project(${PROJECT_NAME})

add_subdirectory(src)