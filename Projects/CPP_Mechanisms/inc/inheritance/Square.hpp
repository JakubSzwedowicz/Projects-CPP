#pragma once
#include "Figure.hpp"

class Square : virtual public Figure
{
protected:
    int m_side;
public:
    Square (int a_side = 10, const char* a_name = "My default square");
    explicit Square(unsigned int a_side); // For Figure inheritance
    ~Square() override { std::cout << "Square destructor" << std::endl;};
    int Area() const override;
    int Volume() const override {return -1;};   // Might be empty as well but return...
};