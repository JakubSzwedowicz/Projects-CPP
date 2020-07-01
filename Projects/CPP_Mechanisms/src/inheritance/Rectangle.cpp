#include "Rectangle.hpp"

Rectangle::Rectangle(int a_side, int a_height, const char* a_name) : Figure(a_name), m_side(a_side), m_height(a_height)
{
    std::cout << " Rectangle constructor with three arguments" << std::endl;
}

int Rectangle::Area() const {
    return m_height * m_side;
}

Rectangle::Rectangle(unsigned int a_side,unsigned int a_height) : m_side(a_side), m_height(a_height)
{
    std::cout << "Rectangle constructor with two arguments" << std::endl;

}
