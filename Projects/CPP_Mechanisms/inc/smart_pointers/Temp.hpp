#pragma once

class Temp
{
private:
    static int s_all;
    int m_number = 0;
public:
    Temp();
    ~Temp();
    inline int GetNumber() const {return m_number;};
};