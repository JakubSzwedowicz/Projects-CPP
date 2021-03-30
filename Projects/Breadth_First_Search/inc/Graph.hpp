//
// Created by jakub on 27.03.2021.
//

#ifndef BREADTH_FIRST_SEARCH_GRAPH_HPP
#define BREADTH_FIRST_SEARCH_GRAPH_HPP
#pragma once

#include <list>

class Graph{
    int m_vertices;
    std::list<int>* m_adj_edges;
public:
    Graph(int a_vertices) : m_vertices(a_vertices){
        m_adj_edges = new std::list<int>[a_vertices];
    }
    ~Graph(){
        delete[] m_adj_edges;
    }
    void add_edge(int, int);
    void BFS(int);
};
#endif //BREADTH_FIRST_SEARCH_GRAPH_HPP
