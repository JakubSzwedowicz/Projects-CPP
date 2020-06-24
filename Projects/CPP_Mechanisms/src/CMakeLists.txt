

add_library(String String.cpp ${PROJECT_SOURCE_DIR}/inc/String.hpp)

target_include_directories(String PUBLIC ${PROJECT_SOURCE_DIR}/inc/)

target_compile_features(String PUBLIC cxx_std_11)
