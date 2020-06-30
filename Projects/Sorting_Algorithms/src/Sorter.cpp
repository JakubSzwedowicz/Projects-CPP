#include <vector>
#include <algorithm>
#include "Sorter.hpp"
#include "Timer.hpp"
#include <array>

template class Sorter<std::vector<int>>;
template class Sorter<std::string>;
template class Sorter<std::array<int, 10000>>;

template<typename T>
T Sorter<T>::BubbleSort()
{
		T copy_data(m_data);
		bool flag = true;
		int end_sorted = 0;
		Timer timer("BubbleSort");
		while(flag)
		{
				end_sorted++;
				flag = false;
				for(int i = 0; i < m_data.size() - end_sorted; i++)
                {
						if(copy_data.at(i) > copy_data.at(i+1))
						{
                            std::swap(copy_data.at(i), copy_data.at(i+1));
						    flag = true;
						}
				}
		}
		return copy_data;
}

template <typename T>
T Sorter<T>::SelectionSort()
{
    T copy_data(m_data);
    Timer timer("SelectionSort");
    for(int i = 0; i < m_data.size(); i++)
        std::iter_swap(std::min_element(copy_data.begin() + i, copy_data.end()), copy_data.begin() + i);
    return copy_data;
}

template <typename T>
void Sorter<T>::RunAll()
{
    if(!IsSorted(BubbleSort())) std::cout << "Bubble Sort not working" << std::endl;
    if(!IsSorted(SelectionSort())) std::cout << "Selection Sort not working" << std::endl;
    if(!IsSorted(InsertionSort())) std::cout << "Insertion Sort not working" << std::endl;
    if(!IsSorted(QuickSort())) std::cout << " Quick Sort not working" << std::endl;
    if(!IsSorted(ShellSort())) std::cout << " Shell Sort not working" << std::endl;
    if(!IsSorted(DefaultSTDSort())) std::cout << " default std::sort not working" << std::endl;
}

template <typename T>
bool Sorter<T>::IsSorted(const T& a_data)
{
    return std::is_sorted(a_data.begin(), a_data.end());
}

template <typename T>
T Sorter<T>::InsertionSort() {
    T copy_data(m_data);
    int value, j;
    Timer timer("InsertionSort");
    for(int i = 0; i < copy_data.size(); i++)
    {
        value = copy_data.at(i);
        j = i - 1;
        for (; j >= 0 && copy_data.at(j) > value; j--)
            copy_data.at(j + 1) = copy_data.at(j);
        copy_data.at(j+1) = value;
    }
    return copy_data;
}

template <typename T>
T Sorter<T>::QuickSort()
{
    T copy_data(m_data);
    Timer timer("QuickSort");
    actual_QuickSort(copy_data, 0, copy_data.size() -1);
    return copy_data;
}

template <typename T>
void Sorter<T>::actual_QuickSort(T& a_data, int a_low, int a_high)
{
    if(a_low < a_high)
    {
        int pivot = Partition(a_data, a_low, a_high);
        actual_QuickSort(a_data, a_low, pivot-1);
        actual_QuickSort(a_data, pivot+1, a_high);
    }
}

template <typename T>
int Sorter<T>::Partition(T& a_data, int a_low, int a_high)
{
    int pivot = a_data.at(a_high);
    int i, j;
    for(i = a_low, j = a_low; i < a_high; i++)
    {
      if(a_data.at(i) < pivot)
      {
          std::swap(a_data.at(i), a_data.at(j));
          j++;
      }
    }
    std::swap(a_data.at(j), a_data.at(a_high));
    return j;
}
template <typename T>
T Sorter<T>::ShellSort() {
    T copy_data(m_data);
    Timer timer("ShellSort");
    for(int interval = copy_data.size()/2; interval > 0; interval /= 2)
    {
        for(int i = interval; i < copy_data.size(); i++)
        {
            int temp = copy_data.at(i);
            int j;
            for(j = i; j >= interval && copy_data.at(j - interval) > temp; j -= interval)
                copy_data.at(j) = copy_data.at(j - interval);
            copy_data.at(j) = temp;
        }
    }
    return copy_data;
}

template <typename T>
T Sorter<T>::DefaultSTDSort()
{
    T copy_data(m_data);
    Timer timer("DefaultSTDSort");
    std::sort(copy_data.begin(), copy_data.end());
    return copy_data;
}