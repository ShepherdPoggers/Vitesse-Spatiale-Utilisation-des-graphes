#pragma once
#include <queue>

const int NON_VISITE = 0;
const int VISITE = 1;

// Remet toutes les marques à zéro avant un nouveau parcours.
template <typename Graphe>
void reinitialiserMarques(Graphe& g)
{
    for (int v = 0; v < g.n(); ++v) {
        g.setMark(v, NON_VISITE);
    }
}

// Visite les sommets accessibles depuis le sommet de départ.
template <typename Graphe, typename Visite>
void BFS(Graphe& g, int debut, Visite visiter)
{
    std::queue<int> file;
    file.push(debut);
    g.setMark(debut, VISITE);

    while (!file.empty()) {
        int v = file.front();
        file.pop();
        visiter(v);

        for (int w = g.first(v); w < g.n(); w = g.next(v, w)) {
            if (g.getMark(w) == NON_VISITE) {
                g.setMark(w, VISITE);
                file.push(w);
            }
        }
    }
}