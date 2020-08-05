cmake_minimum_required(VERSION 3.1)

project(Exponentiation_By_Squaring
        DESCRIPTION "Project testing Fast expononentiation aka. Exponentiation by squaring"
        VERSION 1.0
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

add_executable(App main.cpp Functions.cpp)