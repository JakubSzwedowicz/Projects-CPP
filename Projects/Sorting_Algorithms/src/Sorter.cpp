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
						if(copy_data[i] > copy_data[i+1])
						{
                            std::swap(copy_data[i], copy_data[i+1]);
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
    if(!IsSorted(OldInsertionSort())) std::cout << "OldInsertion Sort not working" << std::endl;
    if(!IsSorted(QuickSort())) std::cout << " Quick Sort not working" << std::endl;
    if(!IsSorted(ShellSort())) std::cout << " Shell Sort not working" << std::endl;
    if(!IsSorted(DefaultSTDSort())) std::cout << " default std::sort not working" << std::endl;
    if(!IsSorted(MergeSort())) std::cout << " Merge Sort not working" << std::endl;
}

template <typename T>
bool Sorter<T>::IsSorted(const T& a_data)
{
    return std::is_sorted(a_data.begin(), a_data.end());
}

template <typename T>
T Sorter<T>::InsertionSort() {
    T copy_data(m_data);
    Timer timer("InsertionSort");
    for(typename T::iterator it = copy_data.begin(); it != copy_data.end(); it++)
    {
        std::rotate(std::upper_bound(copy_data.begin(), it, *it), it, it+1);
    }
    return copy_data;
}

template <typename T>
T Sorter<T>::OldInsertionSort() {
    T copy_data(m_data);
    int value;
    typename T::iterator n_it;
    Timer timer("OldInsertionSort");
    for(typename T::iterator it = copy_data.begin(); it != copy_data.end(); it++)
    {
        value = *it;
        for (n_it = it - 1; n_it >= copy_data.begin() && *n_it > value; n_it--)
            *(n_it+1) = *(n_it);
        *(n_it + 1) = value;
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
    int pivot = a_data[a_high];
    int i, j;
    for(i = a_low, j = a_low; i < a_high; i++)
    {
      if(a_data[i] < pivot)
      {
          std::swap(a_data[i], a_data[j]);
          j++;
      }
    }
    std::swap(a_data[j], a_data[a_high]);
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
            int temp = copy_data[i];
            int j;
            for(j = i; j >= interval && copy_data[j - interval] > temp; j -= interval)
                copy_data[j] = copy_data[j - interval];
            copy_data[j] = temp;
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

template <typename T>
T Sorter<T>::MergeSort()
{
    T copy_data(m_data);
    Timer timer("MergeSort");
    ActualMergeSort(copy_data, 0, copy_data.size() - 1);
    return copy_data;
}

template<typename T>
void Sorter<T>::ActualMergeSort(T &a_data, int a_low, int a_high) {


    if(a_low != a_high)
    {
        int split = (a_low + a_high)/2;
        ActualMergeSort(a_data, a_low, split);
        ActualMergeSort(a_data, split + 1, a_high);

        int left_size = split - a_low + 1;
        int right_size = a_high - split;
        int left_array[left_size], right_array[right_size]; // Valid since C99

        std::copy(a_data.begin() + a_low, a_data.begin() + a_low + left_size, left_array);
        std::copy(a_data.begin() + a_low + left_size, a_data.begin() + a_high + 1, right_array);

        int i = 0, j = 0;
        while(i != left_size && j != right_size)
        {
            if(left_array[i] <= right_array[j])
            {
                a_data[a_low + i + j] = left_array[i];
                i++;
            }
            else
            {
                a_data[a_low + i + j] = right_array[j];
                j++;
            }
        }
        for(; i != left_size; i++)
            a_data[a_low + i + j] = left_array[i];
        for(; j != right_size; j++)
            a_data[a_low + i + j] = right_array[j];

    }
}
