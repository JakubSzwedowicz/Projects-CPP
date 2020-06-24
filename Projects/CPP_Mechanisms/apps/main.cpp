#include <iostream>
#include "Entity.hpp"


int main()
{
		Entity<char> entity1("I Love PWr");
		entity1.Print();

		Entity<char> entity2((String<char>)"I Love W10");
		entity2.Print();
		
		entity2 = entity1;
		entity2.Print();

		std::cin.get();
		return 0;
}
