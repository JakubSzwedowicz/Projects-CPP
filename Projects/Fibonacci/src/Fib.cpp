#include <iostream>

const int FibArraySize = 101;
 

long mySlowFib(const int& number)
{
	if(number < 2)
		return number;
	else
		return mySlowFib(number-1) + mySlowFib(number-2);
}

long myFastFib(const int& number)
{
	static long FibResoults[FibArraySize] = {};
	if(FibResoults[number] != 0)
		return FibResoults[number];
	else
	{
		if(number < 2)
			return FibResoults[number] = number;
		else
			return (FibResoults[number-1] = myFastFib(number-1)) + (FibResoults[number-2] = myFastFib(number-2));
	}
}

long myEvenFasterFib(const int& number)
{
	static long FibResoults[FibArraySize] = {0, 1};
	if(number > FibArraySize)
	{
		std::cout << "Wprowadzono zbyt duza liczbe!" << std::endl;
		return -1;		
	}
	if(FibResoults[2] == 0)		//Calculating array beforehand, i.e. bottom up approach
		for(int i = 2; i < FibArraySize; i++)
			FibResoults[i] = FibResoults[i-1] + FibResoults[i-2];
	
	return FibResoults[number];
}
