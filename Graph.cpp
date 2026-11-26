#include "Graph.h"
#include <cassert>

// ----- Edge -----

Edge::Edge() { vert = -1; wt = -1; }
Edge::Edge(int v, double w) { vert = v; wt = w; }
int Edge::vertex() { return vert; }
double Edge::weight() { return wt; }

// ----- Graph -----

template <typename T>
Graph<T>::Graph(const std::vector<T>& listeSommets)
{
    sommets = listeSommets;
    Init(static_cast<int>(sommets.size()));
}

template <typename T>
Graph<T>::~Graph()
{
    delete[] mark;

    for (int i = 0; i < numVertex; i++)
        delete vertex[i];

    delete[] vertex;
}

template <typename T>
void Graph<T>::Init(int n)
{
    numVertex = n;
    numEdge = 0;

    mark = new int[n];
    for (int i = 0; i < numVertex; i++)
        mark[i] = 0;

    vertex = new std::list<Edge>*[numVertex];
    position.resize(numVertex);

    for (int i = 0; i < numVertex; i++)
        vertex[i] = new std::list<Edge>();
}

template <typename T>
int Graph<T>::n() { return numVertex; }

template <typename T>
int Graph<T>::e() { return numEdge; }

template <typename T>
int Graph<T>::first(int v)
{
    if (vertex[v]->size() == 0)
        return numVertex;

    position[v] = vertex[v]->begin();
    return position[v]->vertex();
}

template <typename T>
int Graph<T>::next(int v, int w)
{
    if (isEdge(v, w)) {
        auto it = position[v];
        it++;

        if (it != vertex[v]->end()) {
            position[v]++;
            return position[v]->vertex();
        }
    }

    return numVertex;
}

template <typename T>
void Graph<T>::setEdge(int i, int j, double weight)
{
    assert(weight > 0);
    Edge currEdge(j, weight);

    if (isEdge(i, j)) {
        position[i] = vertex[i]->erase(position[i]);
        vertex[i]->insert(position[i], currEdge);
    }
    else {
        numEdge++;

        for (position[i] = vertex[i]->begin();
            position[i] != vertex[i]->end();
            position[i]++) {
            if (position[i]->vertex() > j)
                break;
        }

        vertex[i]->insert(position[i], currEdge);
    }
}

template <typename T>
void Graph<T>::delEdge(int i, int j)
{
    if (isEdge(i, j)) {
        position[i] = vertex[i]->erase(position[i]);
        numEdge--;
    }
}

template <typename T>
bool Graph<T>::isEdge(int i, int j)
{
    for (position[i] = vertex[i]->begin();
        position[i] != vertex[i]->end();
        position[i]++) {
        if (position[i]->vertex() == j)
            return true;
    }

    return false;
}

template <typename T>
double Graph<T>::weight(int i, int j)
{
    if (isEdge(i, j))
        return position[i]->weight();

    return 0;
}

template <typename T>
int Graph<T>::getMark(int v) { return mark[v]; }

template <typename T>
void Graph<T>::setMark(int v, int val) { mark[v] = val; }

template <typename T>
const T& Graph<T>::sommet(int indice) const
{
    return sommets.at(indice);
}

// À changer
template class Graph<int>;