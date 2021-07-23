//
// Author: JakubSzwedowicz
// Date: 06.07.2021.
// e-mail: kuba.szwedowicz@gmail.com 
//

#ifndef NETWORKING_PROJECT_TCPIPACTIONS_HPP
#define NETWORKING_PROJECT_TCPIPACTIONS_HPP

#include "asio.hpp"
#include "asio/ts/buffer.hpp"
#include "asio/ts/internet.hpp"

class TCPIP_Actions {
public:
    TCPIP_Actions(const std::string& mIp);

    TCPIP_Actions();

    struct Executor {
    private:
        TCPIP_Actions* m_outer;
    public:
        Executor(TCPIP_Actions* a_outer)
                : m_outer(a_outer) {};

        void set_endpoint();

        void set_endpoint(const std::string& a_ip);

        void connect_to_ip();

        void send_request(const std::string& a_request);

        void receive_request();
    };
    asio::error_code& get_ec();

    asio::io_context& get_context();

    asio::ip::tcp::socket& get_socket();

    std::string& get_ip();

    asio::ip::tcp::endpoint& get_endpoint();

    std::vector<char>& get_buffer();

public:
    Executor executor{this};
private:
    asio::error_code m_ec;
    asio::io_context m_context;
    asio::ip::tcp::socket m_socket;
    asio::ip::tcp::endpoint m_endpoint;
    std::vector<char> m_buffer;
    std::string m_ip;
};


#endif //NETWORKING_PROJECT_TCPIPACTIONS_HPP
