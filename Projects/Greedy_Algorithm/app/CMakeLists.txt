add_executable(APP main.cpp)

set(INCLUDES_DIR ${PROJECT_SOURCE_DIR}/inc/)

target_include_directories(APP PRIVATE ${INCLUDES_DIR})

target_link_libraries(APP PRIVATE MONEY_CHANGE)