#include "Functions.hpp"
#include <chrono>
#include <iostream>



namespace Utilities {
        Timer::Timer() {
            start = std::chrono::high_resolution_clock::now();
        }
        Timer::~Timer() {
            auto end = std::chrono::high_resolution_clock::now();
            auto diff = end - start;
            float ms = diff.count() * 1000.0f;
            std::cout << "Execution took: " << ms << "ms" << std::endl;
        }

    long double FastPower(long a_base, int a_exponent)
    {
        if(a_exponent < 0)
            return 1/ FastPower(a_base, -a_exponent);
        else if(a_exponent == 0)
            return 1;
        else if(a_exponent == 1)
            return a_base;
        else if(a_exponent % 2 == 0)
            return FastPower(a_base*a_base, a_exponent/2);
        else
            return a_base * FastPower(a_base*a_base, (a_exponent - 1)/2);
    }
}
