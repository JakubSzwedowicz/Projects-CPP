//
// Author: JakubSzwedowicz
// Date: 06.07.2021.
// e-mail: kuba.szwedowicz@gmail.com 
//
#include <iostream>
#include <array>
#include <string>

#include "TCPIP_Actions.hpp"
#include "asio.hpp"
#include "asio/ts/internet.hpp"
#include "asio/ts/buffer.hpp"
#include "gtest/gtest.h"

struct TCPIPTest : public ::testing::Test {
protected:
    constexpr static std::array s_ip_addresses{
            "93.184.216.34"
    };
};

TEST_F(TCPIPTest, TestEstablishingConnectionTCPIP) {
    TCPIP_Actions actions;
    for (auto& ip_address : s_ip_addresses) {
        actions.executor.set_endpoint(ip_address);
        actions.executor.connect_to_ip();
        ASSERT_TRUE(!actions.get_ec()) << "[INFO] Couldn't connect with the ip: " << ip_address;
    }
}

TEST_F(TCPIPTest, TestReceivingDataTCPIP) {
    TCPIP_Actions actions;
    for (auto& ip_address : s_ip_addresses) {
        actions.executor.set_endpoint(ip_address);
        actions.executor.connect_to_ip();
        actions.executor.send_request("GET /index.html HTTP/1.1\r\n"
                                      "Host: example.com\r\n"
                                      "Connection: close\r\n\r\n"
                                      );
        actions.get_socket().wait(actions.get_socket().wait_read);
        actions.executor.receive_request();
        ASSERT_TRUE(!actions.get_ec()) << "[INFO] Couldn't connect with the ip: " << ip_address;
    }
}