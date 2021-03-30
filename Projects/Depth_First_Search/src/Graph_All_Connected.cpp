//
// Created by jakub on 27.03.2021.
//

#include "Graph_All_Connected.hpp"
#include <vector>
#include <iostream>
#include <iterator>

void Graph_All_Connected::DFS(int a_depth) {
    std::vector<bool> visited(m_numbers.size(), false);
    std::vector<int> numbers;
    numbers.reserve(a_depth);
    for(int i = 0; i < m_numbers.size(); i++){
        if(m_numbers[i] > 2){
            continue;
        }
        visited[i] = true;
        numbers.push_back(m_numbers[i]);
        travel_DFS(i, numbers,visited, 1, a_depth);
        numbers.pop_back();
        visited[i] = false;
    }
}

void Graph_All_Connected::travel_DFS(int a_index, std::vector<int>& a_numbers, std::vector<bool>& a_visited, int a_curr_depth, int a_max_depth) {
    if(a_curr_depth >= a_max_depth){
        std::cout
        << a_numbers[0] << a_numbers[1]
        << ":" << a_numbers[2] << a_numbers[3]
        << ":" << a_numbers[4] << a_numbers[5] << std::endl;
        return;
    }
    bool accepted = true;
    for(int i = 0; i < m_numbers.size(); i++){
        if(a_visited[i] == false){
            switch(a_numbers.size()){
                case 1:
                    if(a_numbers[0] * 10 + m_numbers[i] > 23){
                        accepted = false;
                    }
                    break;
                case 2:
                    if(a_numbers[i] > 5){
                        accepted = false;
                    }
                    break;
                case 3:
                    if(a_numbers[2] * 10 + m_numbers[i] > 59){
                        accepted = false;
                    }
                    break;
                case 4:
                    if(a_numbers[i] > 5){
                        accepted = false;
                    }
                    break;
                case 5:
                    if(a_numbers[4] * 10 + m_numbers[i] > 59){
                        accepted = false;
                    }
                    break;
            }
            if(!accepted){
                accepted = true;
                continue;
            }
            a_visited[i] = true;
            a_numbers.push_back(m_numbers[i]);
            travel_DFS(i, a_numbers, a_visited, a_curr_depth + 1, a_max_depth);
            a_numbers.pop_back();
            a_visited[i] = false;
        }
    }
}
