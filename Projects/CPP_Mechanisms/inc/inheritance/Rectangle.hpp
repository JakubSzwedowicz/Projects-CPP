#pragma once
#include "Figure.hpp"

class Rectangle : virtual public Figure
{
protected:
    int m_side;
    int m_height;
public:
    Rectangle(int, int, const char* = "My default rectangle");
    explicit Rectangle(unsigned int, unsigned  int);
    ~Rectangle() noexcept {std::cout << "Rectangle Destructor" << std::endl;};
    int Area() const override;
    int Volume() const override {return -1;};     // Might be empty but return
};