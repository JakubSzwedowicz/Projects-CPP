//
// Author: JakubSzwedowicz
// Date: 06.07.2021.
// e-mail: kuba.szwedowicz@gmail.com 
//
#include <iostream>

#include "TCPIP_Actions.hpp"


TCPIP_Actions::TCPIP_Actions(const std::string& a_ip)
        : m_socket(m_context), m_ip(a_ip) {}

TCPIP_Actions::TCPIP_Actions()
        : TCPIP_Actions("") {}

asio::error_code& TCPIP_Actions::get_ec() {
    return m_ec;
}

asio::io_context& TCPIP_Actions::get_context() {
    return m_context;
}

asio::ip::tcp::socket& TCPIP_Actions::get_socket() {
    return m_socket;
}

std::string& TCPIP_Actions::get_ip() {
    return m_ip;
}

asio::ip::tcp::endpoint& TCPIP_Actions::get_endpoint() {
    return m_endpoint;
}

std::vector<char>& TCPIP_Actions::get_buffer() {
    return m_buffer;
}

void TCPIP_Actions::Executor::set_endpoint() {
    set_endpoint(m_outer->m_ip);
}

void TCPIP_Actions::Executor::set_endpoint(const std::string& a_ip) {
    m_outer->m_ip = a_ip;
    m_outer->m_endpoint.address(asio::ip::make_address(a_ip, m_outer->m_ec));
}

void TCPIP_Actions::Executor::connect_to_ip() {
    m_outer->m_socket.connect(m_outer->m_endpoint, m_outer->m_ec);
}

void TCPIP_Actions::Executor::send_request(const std::string& a_request) {
    m_outer->m_socket.write_some(asio::buffer(a_request.data(), a_request.size()), m_outer->m_ec);
}

void TCPIP_Actions::Executor::receive_request() {
    size_t bytes = m_outer->m_socket.available();
    assert(bytes != 0);
    m_outer->m_buffer.clear();
    m_outer->m_buffer.reserve(bytes);
    m_outer->m_socket.read_some(asio::buffer(m_outer->m_buffer.data(), m_outer->m_buffer.size()), m_outer->m_ec);
}

