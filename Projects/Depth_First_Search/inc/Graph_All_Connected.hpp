//
// Created by jakub on 27.03.2021.
//

#ifndef DEPTH_FIRST_SEARCH_GRAPH_ALL_CONNECTED_HPP
#define DEPTH_FIRST_SEARCH_GRAPH_ALL_CONNECTED_HPP

#include <vector>

class Graph_All_Connected{
private:
    std::vector<int> m_numbers;
public:
    Graph_All_Connected(const std::vector<int>& a_numbers) : m_numbers(a_numbers){};
    Graph_All_Connected(std::vector<int>&& a_numbers) : m_numbers(std::move(a_numbers)){};
    void DFS(int);
private:
    void travel_DFS(int, std::vector<int>&, std::vector<bool>&, int, int);
};
#endif //DEPTH_FIRST_SEARCH_GRAPH_ALL_CONNECTED_HPP
