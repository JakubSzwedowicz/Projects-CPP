#include <iostream>
#include "Functions.hpp"
#include <cmath>

int main() {
    {
        Utilities::Timer timer;
        std::cout << Utilities::FastPower(3, -16) << std::endl;
    }
    {
        Utilities::Timer timer;
        std::cout << std::pow(3, -16) << std::endl;
    }
    return 0;
}
