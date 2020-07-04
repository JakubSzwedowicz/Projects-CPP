#include "People.hpp"
#include <iostream>

People::People(int a_age, double a_grade, const char* a_name) : m_age(a_age), m_grade(a_grade), m_name(a_name)
{
    std::cout << "People constructor" << std::endl;
}
People::~People()
{
    std::cout << "People destructor" << std::endl;
}

People& People::operator=(const People& a_data) {
    if(this == &a_data)
        return *this;
    else
    {
        m_age = a_data.m_age;
        m_grade = a_data.m_grade;
        m_name = a_data.m_name;
        return *this;
    }
}

People::People(const People& a_people)
{
    std::cout << "People copy constructor" << std::endl;
    m_name = a_people.m_name;
    m_age = a_people.m_age;
    m_grade = a_people.m_grade;
}

std::ostream &operator<<(std::ostream &a_out, People &a_people)
{
    a_out << "Data: \n\t name: " << a_people.m_name << "\n\t age: " << a_people.m_age << "\n\t grade: " << a_people.m_grade << std::endl;
    return a_out;
}
