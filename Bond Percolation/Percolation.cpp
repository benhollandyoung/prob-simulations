#include "Percolation.h"

#include <iostream>
#include <vector> 
#include <random>
#include <iomanip>
#include <stack>
#include <set>
#include <fstream>
using namespace std;

// Constructor
Percolation::Percolation(int radius, double probability)
    : n(radius), p(probability), rng(std::random_device{}()), dist(0.0, 1.0)  {

    generateGraph();
}

void Percolation::checkAndAdd(std::pair<int,int> a, std::pair<int,int> b, std::set<std::pair<std::pair<int,int>,std::pair<int,int>>>& visitedEdges) {
    if (b.first < 0 || b.first >= n || b.second < 0 || b.second >= n)
        return;
    if (dist(rng) < p) {
        auto edge = std::minmax(a, b);
        if (visitedEdges.find(edge) == visitedEdges.end()) {
            visitedEdges.insert(edge);
            edgeList[a].insert(b);
            edgeList[b].insert(a);
        }
    }
}

void Percolation::generateGraph() {
    std::set<std::pair<std::pair<int,int>,std::pair<int,int>>> visitedEdges; //if ((x,y),(z,w)) in visitedEdges then don't need to sample that edge again 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // We are working on point (i,j) we have 4 edges to consider

            std::pair<int,int> from = {i,j};

            checkAndAdd(from, {i+1, j}, visitedEdges);
            checkAndAdd(from, {i, j+1}, visitedEdges);
            checkAndAdd(from, {i-1, j}, visitedEdges);
            checkAndAdd(from, {i, j-1}, visitedEdges);


        }
    }
}


void Percolation::drawGraph() {
    std::ofstream file("edges.csv");
    for (const auto& [from, neighbours] : edgeList) {
        for (const auto& to:neighbours) {
            if (from < to) {
                file << from.first << "," << from.second << "," << to.first << "," << to.second << "\n";
            }
        }
    }
    file.close();

}