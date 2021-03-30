add_executable(APP main.cpp)

target_link_libraries(APP PRIVATE GRAPH)

target_compile_features(APP PRIVATE cxx_std_14)

target_include_directories(APP PRIVATE ${PROJECT_SOURCE_DIR}/inc/)