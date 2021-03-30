//
// Created by jakub on 27.03.2021.
//

#ifndef DEPTH_FIRST_SEARCH_GRAPH_HPP
#define DEPTH_FIRST_SEARCH_GRAPH_HPP
#pragma once

#include <list>
#include <memory>

class Graph{
private:
    int m_vertices;
    std::list<int>* m_adj_edges;
public:
    Graph(int a_vertices) : m_vertices(a_vertices) {
        m_adj_edges = new std::list<int>[a_vertices];
    }
    void add_edge(int a_f, int a_s){
        m_adj_edges[a_f].push_back(a_s);
    }
    void DFS();
private:
    void travel_DFS(int, std::unique_ptr<bool[]>&);
};
#endif //DEPTH_FIRST_SEARCH_GRAPH_HPP
