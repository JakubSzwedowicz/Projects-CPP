#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <random>
#include <chrono>
#include "Sorter.hpp"
#include <array>

template <typename T>
void Print(const T& Container)
{
    for(auto& k : Container)
        std::cout << k << ' ';
    std::cout << std::endl;
}

int main()
{
	std::vector<int> myNumbers(10000);
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::iota(myNumbers.begin(), myNumbers.end(), 0);
	std::shuffle(myNumbers.begin(), myNumbers.end(), std::default_random_engine(seed));

	Sorter<std::vector<int>> sorter(myNumbers);

//    Print(sorter.BubbleSort());
//    Print(sorter.SelectionSort());
//    Print(sorter.InsertionSort());
//    Print(sorter.QuickSort());
//    Print(sorter.ShellSort());
//    Print(sorter.DefaultSTDSort());
//    Print(sorter.MergeSort());
    sorter.RunAll();
	return 0;
}
