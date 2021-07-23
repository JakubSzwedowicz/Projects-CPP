//
// Author: JakubSzwedowicz
// Date: 06.07.2021.
// e-mail: kuba.szwedowicz@gmail.com 
//

#ifndef NETWORKING_PROJECT_TEST_NETWORKING_HPP
#define NETWORKING_PROJECT_TEST_NETWORKING_HPP

#include "asio.hpp"

class test_networking{
public:
    static void test();
    static void receive_data(asio::ip::tcp::socket& a_socket);
private:
    static std::vector<char> m_buffer;
};

#endif //NETWORKING_PROJECT_TEST_NETWORKING_HPP
