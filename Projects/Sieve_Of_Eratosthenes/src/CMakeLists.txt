set(INCLUDES ${PROJECT_SOURCE_DIR}/inc/)

add_library(FUNCTIONS Functions.cpp ${INCLUDES}/Functions.hpp)

target_include_directories(FUNCTIONS PUBLIC ${INCLUDES})
target_compile_features(FUNCTIONS PUBLIC cxx_std_14)