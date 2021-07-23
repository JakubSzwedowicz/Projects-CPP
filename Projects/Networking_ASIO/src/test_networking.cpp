//
// Author: JakubSzwedowicz
// Date: 06.07.2021.
// e-mail: kuba.szwedowicz@gmail.com 
//
#include <iostream>
#include <chrono>

#include "asio.hpp"
#include "asio/ts/buffer.hpp"
#include "asio/ts/internet.hpp"

#include "test_networking.hpp"

std::vector<char> test_networking::m_buffer(20 * 1024);

void test_networking::test() {
    asio::error_code ec;

    // create a "context" - essentially the platform specific interface
    asio::io_context context;

    asio::io_context::work idle_work_for_context(context);

    std::thread thread_context = std::thread([&]() {context.run();});

    // Get the address of somewhere we wish to connect to, doesn't necessarily has to be internet but might as well be
    asio::ip::tcp::endpoint endpoint(asio::ip::make_address("51.38.81.49", ec), 80);

    // Create a socket, the context will deliver the implementation
    asio::ip::tcp::socket socket(context);

    // Tell socket to try and connect
    socket.connect(endpoint, ec);

    if (!ec) {
        std::cout << "Connected!" << std::endl;
    } else {
        std::cout << "Failed to connect to address: \n" << ec.message() << std::endl;
    }

    if (socket.is_open()) {
        receive_data(socket);

        std::string sRequest =
                "GET /index.html HTTP/1.1\r\n"
                "Host: david-barr.co.uk\r\n"
                "Connection: close\r\n\r\n";

        socket.write_some(asio::buffer(sRequest.data(), sRequest.size()), ec);

        using namespace std::chrono_literals;
        std::this_thread::sleep_for(20000ms);

        context.stop();
        if(thread_context.joinable()) thread_context.join();
    }
}

void test_networking::receive_data(asio::ip::tcp::socket& a_socket) {
    a_socket.async_read_some(asio::buffer(m_buffer.data(), m_buffer.size()),
                             [&](std::error_code ec, std::size_t length) {
                                 if (!ec) {
                                     std::cout << "\n\nRead " << length << " bytes\n\n";
                                     for (int i = 0; i < length; i++) {
                                         std::cout << m_buffer[i];
                                     }
                                     receive_data(a_socket);
                                 }
                             });
}