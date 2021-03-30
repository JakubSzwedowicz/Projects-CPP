cmake_minimum_required(VERSION 3.16)

project(Breadth_First_Search
        VERSION 1.0
        DESCRIPTION "Project testing usage of Breadth first search algorithm"
        LANGUAGES CXX
        )

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)
add_subdirectory(app)