//
// Created by jakub on 27.02.2021.
//

#ifndef LIS_LIS_HPP
#define LIS_LIS_HPP

#include <vector>

int getLIS(const std::vector<int>& a_array) {
    int LIS[a_array.size()];
    int res = 0;
    for(int i = 0; i < a_array.size(); i++){
        LIS[i] = 1;
        for(int j = 0; j != i; j++){
            if(a_array[i] > a_array[j]){
                int maybeNewMax = LIS[j] + 1;
                if(maybeNewMax > LIS[i]){
                    LIS[i] = maybeNewMax;
                    if(maybeNewMax > res){
                        res = maybeNewMax;
                    }
                }
            }
        }
    }
    return res;
}

#endif //LIS_LIS_HPP
