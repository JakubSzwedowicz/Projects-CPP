#include <iostream>
#include "Graph.hpp"

int main() {
    Graph g(6);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 4);
    g.add_edge(3, 4);
    g.add_edge(3, 5);
    g.add_edge(4, 3);
    g.add_edge(4, 5);
    g.BFS(0);
    return 0;
}
