#include "Square.hpp"

int Square::Area() const
{
    return m_side*m_side;
};

Square::Square(unsigned int a_side) : m_side(a_side) {
    std::cout <<"Square constructor with single argument" << std::endl;
}

Square::Square(int a_side, const char *a_name) : m_side(a_side), Figure(a_name)
{
    std::cout << "Square constructor with two arguments" << std::endl;
}
