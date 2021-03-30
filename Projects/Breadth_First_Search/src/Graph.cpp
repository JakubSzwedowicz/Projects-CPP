//
// Created by jakub on 27.03.2021.
//

#include <iostream>
#include <vector>
#include <queue>
#include "Graph.hpp"

void Graph::add_edge(int a_first, int a_second) {
    m_adj_edges[a_first].push_back(a_second);
}

void Graph::BFS(int a_start) {
    std::vector<bool> visited(m_vertices, false);

    std::queue<int> queue;
    visited[a_start] = true;
    queue.push(a_start);

    while(!queue.empty()){
        a_start = queue.front();
        std::cout << a_start << " ";
        queue.pop();

        for(auto it = m_adj_edges[a_start].begin(); it != m_adj_edges[a_start].end(); ++it){
            if(!visited[*it]){
                visited[*it] = true;
                queue.push(*it);
            }
        }
    }
}
