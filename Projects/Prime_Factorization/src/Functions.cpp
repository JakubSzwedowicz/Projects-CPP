#include <iostream>
#include <vector>

namespace Functions
{
	std::vector<int> SlowPrimeFact(const int& n)
	{
		std::vector<int> results;
		int number = n;
		for(int i = 2 ; number != 1 && number != -1; i++)
			if(number % i == 0)
			{
				number /= i;
				results.push_back(i);
				i--;
			}
		if(n < 0)
			results.at(0) = -results.at(0);
		return results;
	}

	std::vector<int> FastPrimeFact(const int& n)
	{
		std::vector<int> results;
		int BasicDividers[] = {2, 3, 5, 7};	
		int number = n;
		for(int i = 0 ; i < 4 && number != 1 && number != -1; i++)
			if(number % BasicDividers[i] == 0)
			{
				number /= BasicDividers[i];
				results.push_back(BasicDividers[i]);
				i--;
			}
		for(int i = 11; number != 1 && number != -1; i += 2)
		{
			if(number % i == 0)
			{
				number /= i;
				results.push_back(i);
				i -= 2;
			}
		}
		if(n < 0)
			results.at(0) = -results.at(0);
		return results;
	}
}
