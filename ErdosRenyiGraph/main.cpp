


#include <iostream>
#include "ErdosRenyiGraph.h"

int main() {
    std::cout << "Erdos-Renyi Graph Simulation\n";

    int n;
    std::cout << "How many vertices? \n";
    std::cin >> n;

    double p;
    std::cout << "What is edge probability?? \n";
    std::cin >> p;


    ErdosRenyiGraph graph(n, p);
    graph.printAdjacencyMatrix();
    graph.printStatistics();
    graph.printEdges();
    graph.exportEdgeList("graph_edges.txt");
    system("\"/Users/benholland/Desktop/MISC/learning c++/week 1/.venv/bin/python\" draw_graph.py");

    return 0;
}

