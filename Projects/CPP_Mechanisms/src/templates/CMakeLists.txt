set(TEMPLATES_INCLUDES_DIR ${PROJECT_SOURCE_DIR}/inc/templates/)

add_library(String String.cpp ${TEMPLATES_INCLUDES_DIR}/String.hpp)

target_include_directories(String PUBLIC ${TEMPLATES_INCLUDES_DIR}/)

target_compile_features(String PUBLIC cxx_std_11)