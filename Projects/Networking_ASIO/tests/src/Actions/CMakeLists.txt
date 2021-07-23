add_library(TCPIP_ACTIONS STATIC TCPIP_Actions.cpp)

target_include_directories(TCPIP_ACTIONS PUBLIC ${PROJECT_SOURCE_DIR}/tests/src/Actions/)

target_link_libraries(TCPIP_ACTIONS PRIVATE ASIO)

target_compile_features(TCPIP_ACTIONS PRIVATE cxx_std_17)