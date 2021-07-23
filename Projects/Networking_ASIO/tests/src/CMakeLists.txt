#set(TEST_INCLUDES_DIR "${gtest_SOURCE_DIR}/include" "${gtest_SOURCE_DIR}")

add_executable(TEST_TCP_IP TCPIPTest.cpp)
set(V_ALL_TESTS TEST_TCP_IP)

#add_library(ALL_TESTS INTERFACE)
#target_link_libraries(ALL_TESTS INTERFACE TEST_TCP_IP)

target_link_libraries(${V_ALL_TESTS} PRIVATE TCPIP_ACTIONS ASIO gtest_main)
#target_include_directories(${V_ALL_TESTS} PRIVATE ${TEST_INCLUDES_DIR})

add_test(NAME TEST_TCP_IP COMMAND TEST_TCP_IP)

add_subdirectory(Actions)