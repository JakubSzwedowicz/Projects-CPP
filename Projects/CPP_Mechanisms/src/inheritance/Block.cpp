#include "Block.hpp"
#include <string>

Block::Block(unsigned int a_basis, unsigned int a_sides, unsigned int a_height, int a_num_basis, int a_num_sides, const char* a_name) : Figure(a_name), Square(a_basis), Rectangle(a_sides, a_height)
{
    m_number_of_basis = a_num_basis;
    m_number_of_sides = a_num_sides;
    m_name = a_name;

    std::cout << "Block constructor" << std::endl;
}

int Block::Area() const {
    return m_number_of_basis * Square::Area() + m_number_of_sides * Rectangle::Area();
}
int Block::Volume() const {
    return m_height * Square::Area();
}
