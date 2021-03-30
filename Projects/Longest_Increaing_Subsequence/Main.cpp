//
// Created by jakub on 27.02.2021.
//

#include "LIS.hpp"
#include <vector>
#include <iostream>
#include <limits>


std::vector<int> get_prefix_sum(const std::vector<int>& A) {
    std::vector<int> res;
    res.reserve(A.size() + 1);
    int sum = 0;
    for (int i : A) {
        sum += i;
        res.push_back(sum);
    }
    return res;

}

int get_prefix_sum_slice(const std::vector<int>& A, int begin, int end) {
    return A[end] - A[begin - 1];
}

int solution(std::vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    std::vector<int> prefix_sum = get_prefix_sum(A);
    int smallest_index = 0;
    double smallest_average = std::numeric_limits<double>::max();
    for (int i = 0; i < prefix_sum.size() - 1; i++) {
        for (int j = i + 1; j < prefix_sum.size(); j++) {
            double average = get_prefix_sum_slice(prefix_sum, i, j) / (j - i + 1.0);
            if (average < smallest_average) {
                smallest_average = average;
                smallest_index = i;
            }
        }
    }
    return smallest_index;
}


void print(const std::vector<int>& a) {
    std::cout << a.size() << std::endl;
    for (int i : a) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> v = {4, 2, 2, 5, 1, 5, 8};
    std::cout << solution(v) << std::endl;
}