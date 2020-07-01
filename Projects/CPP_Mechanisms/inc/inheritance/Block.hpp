#pragma once
#include "Rectangle.hpp"
#include "Square.hpp"


class Block : public Square, public Rectangle
{
private:
    int m_number_of_basis;
    int m_number_of_sides;
public:
    Block(unsigned int, unsigned int, unsigned int, int, int, const char* = "Moj graniastoslup");
    ~Block() {std::cout << "Block destructor" << std::endl;};
    int Volume() const override;
    int Area() const final;
};