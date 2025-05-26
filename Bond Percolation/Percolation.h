#ifndef Percolation_h
#define Percolation_h

#include <vector>
#include <random>
#include <string>
#include <map>
#include <set>

class Percolation {
private:
    double p; // edge presence probability
    int n; // grid size for percolation box
    std::mt19937 rng; // random number generator 
    std::uniform_real_distribution<double> dist; // uniform random variables

    // Helper to attempt adding an edge between two points
    void checkAndAdd(std::pair<int,int> a,
                     std::pair<int,int> b,
                     std::set<std::pair<std::pair<int,int>, std::pair<int,int>>>& visitedEdges);

    // Adjacency list representation of the graph
    std::map<std::pair<int,int>, std::set<std::pair<int,int>>> edgeList;

public:
    // Constructor
    Percolation(int vertices, double probability);

    void generateGraph();
    void resetGraph();
    void drawGraph(); // for visualization/debugging
    bool doesPercolationOccur(); // check if path exists from one boundary to the other
};

#endif // Percolation_h
