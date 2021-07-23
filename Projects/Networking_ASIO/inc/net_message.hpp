//
// Author: JakubSzwedowicz
// Date: 19.07.2021.
// e-mail: kuba.szwedowicz@gmail.com 
//

#ifndef NETWORKING_PROJECT_NET_MESSAGE_HPP
#define NETWORKING_PROJECT_NET_MESSAGE_HPP

#endif //NETWORKING_PROJECT_NET_MESSAGE_HPP

#include <vector>
#include <type_traits>
#include <cstring>

#include "iostream"

namespace olc {
    namespace net {
        template<typename T>
        struct message_header {
            T m_id{};
            uint32_t m_size = 0;
        };

        template<typename T>
        struct message {
            message_header<T> m_header{};
            std::vector<uint8_t> m_body;

            size_t size() const {
                return sizeof(message_header<T>) + m_body.size();
            }

            friend std::ostream& operator<<(std::ostream& a_out, const message<T>& a_msg) {
                a_out << "ID:" << a_msg.m_header.m_id << " Size:" << a_msg.m_header.m_size;
                return a_out;
            }

            template <typename DataType>
            friend message<T>& operator<<(message<T>& a_msg, const DataType& a_data){
                static_assert(std::is_standard_layout<DataType>::value, "Data is too complex to serialize");
                size_t i = a_msg.m_body;
                a_msg.m_body.resize(i + sizeof(DataType));

                a_msg.m_body.push_back(a_data);
                std::memcpy(a_msg.m_body.data() + i, &a_data, sizeof(DataType));
                a_msg.m_header.m_size = a_msg.size();
            }
        };
    }
}