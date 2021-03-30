//
// Created by jakub on 27.03.2021.
//
#include <iostream>
#include "Graph.hpp"
#include "Graph_All_Connected.hpp"

int main(){
    Graph_All_Connected g({1, 2, 3, 4, 5, 6});
    g.DFS(6);

    Graph graph(5);
    graph.add_edge(0, 1);
    graph.add_edge(2, 1);
    graph.add_edge(4, 3);
    graph.DFS();
}
