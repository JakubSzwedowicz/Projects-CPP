add_executable(APP main.cpp)

target_link_libraries(APP PRIVATE GRAPH)
target_link_libraries(APP PRIVATE GRAPH_ALL_CONNECTED)

target_include_directories(APP PRIVATE ${PROJECT_SOURCE_DIR}/inc)

target_compile_features(APP PRIVATE cxx_std_11)