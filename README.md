# Erdos-Renyi Graph Generator

This project implements an **Erdős–Rényi random graph** generator in C++ using the \( G(n, p) \) model. It generates undirected graphs with a given number of vertices and edge probability, and provides tools for printing the graph, computing statistics, and checking connectivity between vertices using **depth-first search (DFS)**.

---

## 📦 Features

- Generate a random undirected graph using the G(n, p) model
- Print the adjacency matrix and edge list
- Compute basic statistics:
  - Total number of edges
  - Average degree
  - Expected edges and degree
  - Graph density
- Check if two nodes are in the same connected component using stack-based DFS

---

## 🛠️ Build Instructions

You need a C++ compiler that supports C++11 or higher. To compile using `clang++`:

```bash
clang++ -std=c++11 ErdosRenyiGraph.cpp -o main
