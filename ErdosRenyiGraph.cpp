#include "ErdosRenyiGraph.h"

#include <iostream>
#include <vector> 
#include <random>
#include <iomanip>
#include <stack>
#include <set>
#include <fstream>
using namespace std;

// Constructor
ErdosRenyiGraph::ErdosRenyiGraph(int vertices, double probability)
    : n(vertices), p(probability), rng(std::random_device{}()), dist(0.0, 1.0), reset(true) {
    adjacencyMatrix.resize(n, std::vector<bool>(n, false));
    generateGraph();
}

void ErdosRenyiGraph::exportEdgeList(const std::string& filename) {
    std::ofstream file(filename);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (adjacencyMatrix[i][j]) {
                file << i << " " << j << "\n";
            }
        }
    }
    file.close();
}

void ErdosRenyiGraph::clearGraph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjacencyMatrix[i][j] = false;
        }
    }
}

void ErdosRenyiGraph::generateGraph() {
    if (!reset) clearGraph();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dist(rng) < p) {
                adjacencyMatrix[i][j] = true;
                adjacencyMatrix[j][i] = true;
            }
        }
    }
}

void ErdosRenyiGraph::printAdjacencyMatrix() {
    std::cout << "Adjacency Matrix:\n  ";
    for (int i = 0; i < n; i++) std::cout << std::setw(3) << i;
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

void ErdosRenyiGraph::printEdges() {
    std::cout << "Edges:\n";
    int edgeCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (adjacencyMatrix[i][j]) {
                std::cout << "(" << i << ", " << j << ")\n";
                edgeCount++;
            }
        }
    }
    std::cout << "Total edges: " << edgeCount << ".\n";
}

void ErdosRenyiGraph::printStatistics() {
    int totalEdges = 0;
    std::vector<int> degrees(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (adjacencyMatrix[i][j]) {
                totalEdges++;
                degrees[i]++;
                degrees[j]++;
            }
        }
    }
    double avgDegree = 0.0;
    for (int deg : degrees) avgDegree += deg;
    avgDegree /= n;

    int maxPossibleEdges = n * (n - 1) / 2;
    double expectedEdges = maxPossibleEdges * p;
    double expectedAvgDegree = (n - 1) * p;

    std::cout << "Graph statistics:\n";
    std::cout << "Number of vertices: " << n << "\n";
    std::cout << "Edge probability: " << p << "\n";
    std::cout << "Actual edges: " << totalEdges << "\n";
    std::cout << "Expected edges: " << std::fixed << std::setprecision(2) << expectedEdges << "\n";
    std::cout << "Actual average degree: " << std::fixed << std::setprecision(2) << avgDegree << "\n";
    std::cout << "Expected average degree: " << std::fixed << std::setprecision(2) << expectedAvgDegree << "\n";
    std::cout << "Graph density: " << std::fixed << std::setprecision(4)
              << (double)totalEdges / maxPossibleEdges << "\n\n";
}

bool ErdosRenyiGraph::sameComponent(int x, int y) {
    std::stack<int> explorationStack;
    std::set<int> visited;

    explorationStack.push(x);
    while (!explorationStack.empty()) {
        int currentNode = explorationStack.top();
        explorationStack.pop();
        if (currentNode == y) return true;
        if (visited.count(currentNode) == 0) {
            visited.insert(currentNode);
            for (int i = 0; i < n; i++) {
                if (adjacencyMatrix[currentNode][i]) {
                    explorationStack.push(i);
                }
            }
        }
    }
    return false;
}

int ErdosRenyiGraph::getDegree(int v) {
    int degree = 0;
    for (int i = 0; i < n; i++) {
        if (adjacencyMatrix[v][i]) degree++;
    }
    return degree;
}

void ErdosRenyiGraph::regenerate(int newN, double newP) {
    if (newN > 0) {
        n = newN;
        adjacencyMatrix.resize(n, std::vector<bool>(n, false));
    }
    if (newP >= 0.0 && newP <= 1.0) {
        p = newP;
    }
    generateGraph();
}