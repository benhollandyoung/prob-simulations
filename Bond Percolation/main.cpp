#include <iostream>
#include "Percolation.h"

int main() {
    std::cout << "Percolation in nxn box Simulation\n";

    int n;
    std::cout << "n = ? \n";
    std::cin >> n;

    double p;
    std::cout << "What is edge probability? \n";
    std::cin >> p;


    Percolation graph(n, p);
    graph.generateGraph();
    graph.drawGraph();
    system("\"/Users/benholland/Desktop/MISC/learning c++/week 1/.venv/bin/python\" draw_graph.py");

    return 0;
}

