#include <iostream>
#include "Functions.hpp"

namespace
{
	bool IsPrime(long n)
		{
			long half = n/2;
			if(n % 2 == 0)
				return false;
			for(long i = 3; i < half; i+=2)
				if(n % i == 0)
					return false;
			return true;
		}
}

long Functions::FindPrime()
	{
		long myPrime = 1;
		char next = 'y';
		while(next == 'y')
		{
			myPrime++;
			while(!IsPrime(myPrime))
				myPrime++;
			std::cout << "Znaleziona liczba pierwsza to: " << myPrime << std::endl;
			std::cout << "Czy chcesz znalezc kolejna? [y/n]" << std::endl;
			std::cin >> next;
		}
		return myPrime;
	}


