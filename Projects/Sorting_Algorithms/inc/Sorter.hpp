#include <iostream>
template <typename T>
class Sorter
{
	private:
		T m_data;

		void actual_QuickSort(T &a_data, int a_low, int a_high);
        int Partition(T &a_data, int low, int high);
        bool IsSorted(const T &a_data);
        void ActualMergeSort(T& a_data, int a_split, int a_size);

        // No longer used:
        T OldInsertionSort();
    public:
        Sorter(const T a_data) : m_data(a_data) {};
        T BubbleSort();
        T SelectionSort();
        T InsertionSort();
		T ShellSort();
        void RunAll();
        T QuickSort();
        T DefaultSTDSort();
        T MergeSort();
};

