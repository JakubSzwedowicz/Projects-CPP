#pragma once
#include <iostream>
#include <chrono>

class Timer
{
private:
	std::chrono::time_point<std::chrono::system_clock> start;
	std::chrono::duration<float> difference;
public:
	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}
	~Timer()
	{
		auto end = std::chrono::high_resolution_clock::now();
		difference = end - start;
		float ms = difference.count() * 1000.0f;
		std::cout << "Czas trwania funckji to: " << ms << "ms " << std::endl << "--------------------------------------------" << std::endl;
	}
};
