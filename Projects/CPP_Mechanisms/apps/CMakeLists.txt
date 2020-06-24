add_executable(app main.cpp)

target_compile_features(app PRIVATE cxx_std_11)

target_link_libraries(app PRIVATE String)

target_include_directories(app PRIVATE ${PROJECT_SOURCE_DIR}/inc)
