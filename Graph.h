#pragma once

#include <cassert>
#include <list>
#include <vector>

// Edge class for Adjacency List graph representation
class Edge {
    int vert;
    double wt;

public:
    Edge();
    Edge(int v, double w);
    int vertex();
    double weight();
};

template <typename T>
class Graph {
private:
    std::list<Edge>** vertex; // List headers
    std::vector<std::list<Edge>::iterator> position; // Current position in each list
    std::vector<T> sommets;
    int numVertex, numEdge; // Number of vertices, edges
    int* mark; // Pointer to mark array
    void Init(int n);

public:
    Graph(const std::vector<T>& listeSommets);
    Graph(const Graph&) = delete;
    Graph& operator=(const Graph&) = delete;
    ~Graph();

    int n();
    int e();
    int first(int v);
    int next(int v, int w);
    void setEdge(int i, int j, double weight);
    void delEdge(int i, int j);
    bool isEdge(int i, int j);
    double weight(int i, int j);
    int getMark(int v);
    void setMark(int v, int val);
    const T& sommet(int indice) const;
};