#pragma once
#include <chrono>

class Timer
{
	private:
            const char* m_name;
			std::chrono::time_point<std::chrono::system_clock> start;
			std::chrono::duration<float> diff;
	public:
			Timer(const char* a_name) : m_name(a_name)
			{
					start = std::chrono::high_resolution_clock::now();
			}
			~Timer()
			{
					auto end = std::chrono::high_resolution_clock::now();
					diff = end - start;  
					float ms = diff.count() * 1000.0f;
					std::cout << "Time measured for " << m_name << " is: " << ms << "ms" << std::endl;
			}
};
