add_executable(App main.cpp)

target_compile_features(App PRIVATE cxx_std_11)

target_link_libraries(App PRIVATE Sorter)

target_include_directories(App PRIVATE ${PROJECT_SOURCE_DIR}/inc)
