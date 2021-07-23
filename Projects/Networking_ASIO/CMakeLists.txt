cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME "Networking project")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(CMAKE_CXX_FLAGS "-Wall -Werror -Wno-missing-braces -O0 -g -std=c++17")

project(${PROJECT_NAME}
        DESCRIPTION "Project focused around the ASIO library"
        VERSION 1.0
        LANGUAGES CXX)
include(CTest)

#include(FetchContent)
#FetchContent_Declare(
#        googletest
#        # Specify the commit you depend on and update it regularly.
#        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
#)
## For Windows: Prevent overriding the parent project's compiler/linker settings
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#FetchContent_MakeAvailable(googletest)

add_subdirectory(app/)
add_subdirectory(src/)
add_subdirectory(libs/)
add_subdirectory(tests/)