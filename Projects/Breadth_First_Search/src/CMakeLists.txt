add_library(GRAPH Graph.cpp)

set(INCLUDES_DIR ${PROJECT_SOURCE_DIR}/inc/)

target_include_directories(GRAPH PUBLIC ${INCLUDES_DIR}/)

target_compile_features(GRAPH PUBLIC cxx_std_14)
