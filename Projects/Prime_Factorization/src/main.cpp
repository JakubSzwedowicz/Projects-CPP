#include <iostream>
#include <vector>
#include "Timer.hpp"

namespace Functions
{
	std::vector<int> SlowPrimeFact(const int&);
	std::vector<int> FastPrimeFact(const int&);
}
template<typename T>
void Print(T Container)
{
	for(auto k : Container)
		std::cout << k << " ";
	std::cout << std::endl;
}

int main()
{
	int number = 0;
	std::cout << "Podaj liczbe do wyznaczenia jej rozkladu na jednomiany: " << std::endl;
	std::cin >> number;
	std::cout << std::endl;
	std::cout << "Liczba: " << number << " rozklada sie na: \n" <<  std::endl;  
	{
		std::cout << "Wolna funkja: " << std::endl;
		Timer timer;
		Print(Functions::SlowPrimeFact(number));
	}
	{
		std::cout << "Szybka funkcja: " << std::endl;
		Timer timer;
		Print(Functions::FastPrimeFact(number));
	}
		return 0;
}
