//
// Created by jakub on 27.03.2021.
//

#include <memory>
#include <iostream>
#include "Graph.hpp"

void Graph::DFS() {
    std::unique_ptr<bool[]> visited = std::make_unique<bool[]>(m_vertices);
    for(int i = 0; i < m_vertices; i++){
        visited[i] = false;
    }

    for(int i = 0; i < m_vertices; i++){
        if(visited[i] == false){
            visited[i] = true;
            travel_DFS(i, visited);
        }
    }
}

void Graph::travel_DFS(int a_vertice, std::unique_ptr<bool[]>& a_visited) {
    std::cout << "Vertice: " << a_vertice << std::endl;
    for(auto it = m_adj_edges[a_vertice].begin(); it != m_adj_edges[a_vertice].end(); ++it){
        if(a_visited[*it] == false){
            a_visited[*it] = true;
            travel_DFS(*it, a_visited);
        }
    }
}
