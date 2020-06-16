#include <iostream>
#include "Timer.hpp"

long mySlowFib(const int&);
long myFastFib(const int&);
long myEvenFasterFib(const int&);

int main()
{
	int number = 0;
	float leap = 0;
	long (*fun_ptr)(const int&);

	
	std::cout << "Wprowadz do ilu liczb maja byc obliczone ciagi Fibonacciego: " << std::endl;
	std::cout << "Najlepiej max 50" << std::endl;
	std::cin >> number;
	leap = number/5;
	/*std::cout << "Wyniki dla wolnej funkcji Fibonacciego (mySlowFib) to: " << std::endl;
	for(int i = 0; i < number+1; i += leap)
	{
		Timer timer;
		std::cout << "Wynik dla i = " << i << " to: " << mySlowFib(i) << std::endl;
	}

	std::cout << std::endl << "Wyniki dla szybkiej funkcji Fibonacciego (myFastFib) to: " << std::endl;
	for(int i = 0; i < number+1; i += leap)
	{
		Timer timer;
		std::cout << "Wynik dla i = " << i << " to: " << myFastFib(i) << std::endl;
	}

	std::cout << std::endl << "Wyniki dla trzeciej funkcji Fibonacciego (myEvenFasterFib) to: " << std::endl;
	for(int
	*/

	for(int i = 0; i < 3; i++)
	{
		if(i == 0)
		{
			fun_ptr = &mySlowFib;
			std::cout << "Wyniki dla wolnej funkcji Fibonacciego (mySlowFib) to: " << std::endl;
		}
		else if(i == 1)
		{
			fun_ptr = &myFastFib;
			std::cout << std::endl << "Wyniki dla szybkiej funkcji Fibonacciego (myFastFib) to: " << std::endl;
		}
		else if(i == 2)
		{
			fun_ptr = &myEvenFasterFib;
			std::cout << std::endl << "Wyniki dla trzeciej funkcji Fibonacciego (myEvenFasterFib) to: " << std::endl;
		}
		for(int j = number%5; j < number+1; j += leap)	//Intentional float to int conversion
		{
			Timer timer;
			std::cout << "wynik dla j = " << j << " to: " << (*fun_ptr)(j) << std::endl;
		}
	}
	return 0;
}
