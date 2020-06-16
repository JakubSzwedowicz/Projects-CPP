#include <iostream>
#include <chrono>

class Timer
{
	private:
		std::chrono::time_point<std::chrono::system_clock> start;
		std::chrono::duration<float> diff;
	public:
		Timer()
		{
			start = std::chrono::high_resolution_clock::now();
		}
		~Timer()
		{
			auto end = std::chrono::high_resolution_clock::now();
			diff = end - start;
			float ms = diff.count() * 1000.0f;
			std::cout << "Czas trwania wynosi: " << ms << "ms" << std::endl;
			std::cout << "--------------------------------------" << std::endl;
		}
};

