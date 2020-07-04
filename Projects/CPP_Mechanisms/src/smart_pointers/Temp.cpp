#include "Temp.hpp"
#include <iostream>

int Temp::s_all = 0;

Temp::Temp() : m_number(++s_all)
{
    std::cout << "Object No. " << m_number << " created" << std::endl;
}

Temp::~Temp()
{
    std::cout << "Object No. " << m_number << " destroyed" << std::endl;
}
