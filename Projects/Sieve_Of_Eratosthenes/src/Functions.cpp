#include "Functions.hpp"
#include <iostream>

std::vector<int> Functions::GeneratePrimes(int a_how_many)
{
    static std::vector<bool> numbers(100, true);
    static std::vector<int> prime_numbers({2});
    std::vector<int> res;

    if(a_how_many > prime_numbers.size())
    {
        while(a_how_many > prime_numbers.size())
        {
            numbers.resize(numbers.size() * 10, true);
            numbers[0] = false;
            numbers[1] = false;
            for(int i = 2; i < numbers.size()/2; i++)
            {
                while(numbers[i] == false) i++;

                for(int j = 2*i; j < numbers.size(); j += i)
                    numbers[j] = false;
                if(i > prime_numbers.back())
                    prime_numbers.push_back(i);
            }
        }
    }
    res.insert(res.begin(), prime_numbers.begin(), prime_numbers.begin() + a_how_many);
    std::cout << "static vector size: " << numbers.size() << " and there are " << prime_numbers.size() << " prime numbers" << std::endl;
    return res;
}