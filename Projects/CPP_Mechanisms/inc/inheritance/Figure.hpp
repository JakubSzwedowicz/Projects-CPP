#pragma once
#include <string>
#include <iostream>

class Figure
{
protected:
    std::string m_name;
public:
    Figure() {std::cout << "Figure constructor" << std::endl;};
    Figure(const char* a_data) : m_name(a_data) {std::cout << "Figure constructor with cont char*" << std::endl;};
    virtual ~Figure() {std::cout << "Figure destructor" << std::endl;};
    virtual int Area() const = 0;
    virtual int Volume() const = 0;
    std::string GetName() {return m_name;};
};