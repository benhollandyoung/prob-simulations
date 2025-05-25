#include <iostream>
#include <vector> 
#include <random>
#include <iomanip>
#include <stack>
#include <set>
using namespace std;

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
    ErdosRenyiGraph(int vertices, double probability) : n(vertices), p(probability), rng(std::random_device{}()), dist(0.0,1.0), reset(true) {
        // Initialising all edges closed
        adjacencyMatrix.resize(n, std::vector<bool>(n,false));
        generateGraph();
    }
    void clearGraph() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adjacencyMatrix[i][j] = false;
            }
        }
    }

    //  Generate random graph
    void generateGraph() {
        // Reset the graph if not reset
        if (reset == false) {
            clearGraph();
        }


        // Open edges if Unif[0,1] < p
        for (int i = 0; i < n; i++) {
            // No self-loops, the double counting is avoided by doing this, each pair (i,j) i!=j is considered only once
            for (int j = i+1; j < n; j++) {
                if (dist(rng) < p) {
                    adjacencyMatrix[i][j] = true;
                    adjacencyMatrix[j][i] = true;
                }
            }
        }
    }

    //  Printing the adjacency matrix
    void printAdjacencyMatrix() {
        std::cout << "Adjacency Matrix: \n";
        std::cout << "  ";
        for (int i = 0; i < n; i++) {
            std::cout << std::setw(3) << i;
        }
        std::cout << "\n";

        for (int i = 0; i < n; i++) {
            std::cout << std::setw(2) << i << " ";
            for (int j = 0; j < n; j++) {
                std::cout << std::setw(3) << (adjacencyMatrix[i][j] ? 1 : 0);
            }
            std::cout << "\n";
        }
        std::cout << "\n";

    }
    //  Printing the edge list
    void printEdges() {
        //  Print edge list
        std::cout << "Edges: \n";

        int edgeCount = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adjacencyMatrix[i][j] == 1) {
                    std::cout << "(" << i << ", " << j << ")\n";
                    edgeCount++;
                }
            }
        }
        std::cout << "Total edges: " << edgeCount << ".\n";
    }

    //  Calculating statistics for the graph
    void printStatistics() {
        int totalEdges = 0;
        std::vector<int> degrees(n, 0);
        
        //  Count edges and degrees
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                totalEdges++;
                degrees[i]++;
                degrees[j]++;

            }
        }

        //  Calculate average degree
        double avgDegree{};
        for (int degree: degrees) {
            avgDegree += degree;
        }
        avgDegree /= n;

        //  Expected results
        int maxPossibleEdges = n * (n-1) / 2;
        double expectedEdges = maxPossibleEdges * p;
        double expectedAvgDegree = (n-1) * p;
        std::cout << "Graph statistics: \n";
        std::cout << "Number of vertices: " << n << "\n";
        std::cout << "Edge probability: " << p << "\n";
        std::cout << "Actual edges: " << totalEdges << "\n";
        std::cout << "Expected edges: " << std::fixed << std::setprecision(2) << expectedEdges << "\n";
        std::cout << "Actual average degree: " << std::fixed << std::setprecision(2) << avgDegree << "\n";
        std::cout << "Expected average degree: " << std::fixed << std::setprecision(2) << expectedAvgDegree << "\n";
        std::cout << "Graph density: " << std::fixed << std::setprecision(4) << (double)totalEdges / maxPossibleEdges << "\n\n";
    }

    //  Check if two vertices are connected
    bool sameComponent(int x, int y) {
        //  Performing a DFS to check if two points are in the same conn'd component, 
        //  start at x, if we ever come across y then we 
        stack<int> explorationStack; // queue of what to explore
        set<int> visited;
        int currentNode;

        explorationStack.push(x);

        while (!explorationStack.empty()) {
            currentNode = explorationStack.top();
            explorationStack.pop();
            if (currentNode == y) {
                return true;
            }

            if (visited.count(currentNode) == 0) {
                visited.insert(currentNode);
                for (int i = 0; i < n; i++) {
                    if (adjacencyMatrix[currentNode][i] == 1) {
                        explorationStack.push(i);
                    }
                }
            }
        }

        return false;

    }

    int getDegree(int v) {
        int degree{};
        for (int i = 0; i < n; i++) {
            if (adjacencyMatrix[v][i] == 1) {
                degree++;
            }
        }
        return degree;
    }

    void regenerate(int newN = -1, double newP = -1.0) {
        if (newN > 0) {
            n = newN;
            adjacencyMatrix.resize(n, std::vector<bool>(n, false));
        }
        if (newP >= 0.0 && newP <= 1.0) {
            p = newP;
        }
        
        generateGraph();
    }


};

int main() {
    std::cout << "Erdos-Renyi Graph Simulation\n";

    std::cout << "Small graph (n=6, p = 0.3)\n";
    ErdosRenyiGraph smallGraph(6, 0.3);
    smallGraph.printAdjacencyMatrix();
    smallGraph.printStatistics();
    smallGraph.printEdges();

    return 0;
}