set(NETWORKING_INCLUDES ${PROJECT_SOURCE_DIR}/inc/)
set(NETWORKING_SOURCES test_networking.cpp net_message.cpp)

add_library(TEST_NETWORKING ${NETWORKING_SOURCES})
target_include_directories(TEST_NETWORKING PUBLIC ${NETWORKING_INCLUDES})
target_link_libraries(TEST_NETWORKING PUBLIC ASIO)

add_library(SRC_LIBS INTERFACE)
target_link_libraries(SRC_LIBS INTERFACE TEST_NETWORKING)
target_compile_features(SRC_LIBS INTERFACE cxx_std_17)
