#pragma once
#include <chrono>

namespace Utilities
{
    long double FastPower(long, int);
    class Timer
    {
    private:
        std::chrono::system_clock::time_point start;
    public:
        Timer();
        ~Timer();
    };
}