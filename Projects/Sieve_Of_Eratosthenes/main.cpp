#include <iostream>
#include <chrono>
#include "Functions.hpp"

std::ostream& operator<<(std::ostream& a_out, const std::vector<int>& a_data)
{
    for(const int& k : a_data)
        a_out << k << ' ';
    return a_out;
};

class Timer
{
private:
    std::chrono::system_clock::time_point start;
public:
    void Start(){
        start = std::chrono::high_resolution_clock::now();
    }
    void End(){
        std::chrono::system_clock::time_point end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> diff;
        diff = end - start;
        float ms = diff.count() * 1000.0f;
        std::cout << "Time measured: " << ms << "ms" << std::endl;
    }
};

int main() {
    Timer timer;
    timer.Start();
    std::cout << Functions::GeneratePrimes(10) << std::endl;
    timer.End();
    timer.Start();
    std::cout << Functions::GeneratePrimes(50) << std::endl;
    timer.End();
    timer.Start();
    std::cout << Functions::GeneratePrimes(100) << std::endl;
    timer.End();
    timer.Start();
    std::cout << Functions::GeneratePrimes(500) << std::endl;
    timer.End();
    timer.Start();
    std::cout << Functions::GeneratePrimes(1000) << std::endl;
    timer.End();
    timer.Start();
    std::cout << Functions::GeneratePrimes(5000) << std::endl;
    timer.End();
    timer.Start();
    std::cout << Functions::GeneratePrimes(10000) << std::endl;
    timer.End();
    timer.Start();
    std::cout << Functions::GeneratePrimes(20000) << std::endl;
    timer.End();
    return 0;
}
