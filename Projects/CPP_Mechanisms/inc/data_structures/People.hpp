#pragma once
#include <string>

class People
{
private:
    int m_age;
    double m_grade;
    std::string m_name;
public:
    People(int = 20, double = 5.0, const char* = "Student");
    People(const People&);
    ~People();
    inline int GetAge() { return m_age;};
    inline double GetGrade() { return m_grade;};
    inline std::string GetArray() {return m_name;};
    People& operator=(const People&);
    friend std::ostream& operator<<(std::ostream& a_out, People& a_people);
};