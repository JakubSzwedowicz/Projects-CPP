//
// Created by jakub on 29.03.2021.
//
#include "Money_Change.hpp"
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

std::vector<int> get_change(int change) {
    std::vector<int> res;
    std::array<int, 8> bills = {1, 2, 5, 10, 20, 50, 100, 200};
    while (change != 0) {
        auto it = std::find_if(bills.rbegin(), bills.rend(), [&](const auto& v) {
            return v <= change;
        });
        while (*it <= change) {
            res.push_back(*it);
            change -= *it;
        }
    }
    return res;
}