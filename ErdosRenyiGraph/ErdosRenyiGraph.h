// ErdosRenyiGraph.h
#include <vector> 
#include <random>
#include <string>
#ifndef ErdosRenyiGraph_h
#define ErdosRenyiGraph_h

class ErdosRenyiGraph {
    private:
    int n; // number of vertices
    double p; // edge probability 
    bool reset; 
    std::vector<std::vector<bool>> adjacencyMatrix;
    std::mt19937 rng; //random number generator 
    std::uniform_real_distribution<double> dist;

    public:
    //  Constructor 
    ErdosRenyiGraph(int vertices, double probability);

    void exportEdgeList(const std::string& filename);

    void clearGraph();

    //  Generate random graph
    void generateGraph();

    //  Printing the adjacency matrix
    void printAdjacencyMatrix();

    //  Printing the edge list
    void printEdges();

    //  Calculating statistics for the graph
    void printStatistics(); 
    

    //  Check if two vertices are connected
    bool sameComponent(int x, int y);

    int getDegree(int v);

    void regenerate(int newN = -1, double newP = -1.0);


};

#endif // ErdosRenyiGraph_h