#include "Node.hpp"
#include "People.hpp"
#include <iostream>

Node::Node(const People &a_data)
{
    m_data = std::make_unique<People>(a_data);
    std::cout << "Filled node constructor" << std::endl;
}
Node::~Node()
{
    std::cout << "Node destructor" << std::endl;
}