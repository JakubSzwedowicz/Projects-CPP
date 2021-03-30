
add_library(Sorter Sorter.cpp)

target_include_directories(Sorter PUBLIC ${PROJECT_SOURCE_DIR}/inc)

target_compile_features(Sorter PUBLIC cxx_std_11)
