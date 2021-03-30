set(INCLUDES_DIR ${PROJECT_SOURCE_DIR}/inc/)

add_library(GRAPH Graph.cpp)
add_library(GRAPH_ALL_CONNECTED Graph_All_Connected.cpp)

target_include_directories(GRAPH PUBLIC ${INCLUDES_DIR})
target_include_directories(GRAPH_ALL_CONNECTED PUBLIC ${INCLUDES_DIR})

target_compile_features(GRAPH PUBLIC cxx_std_11)
target_compile_features(GRAPH_ALL_CONNECTED PUBLIC cxx_std_11)