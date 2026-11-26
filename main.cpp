#include "Graph.h"
#include <cassert>
#include <iostream>
#include <stdexcept>

int main()
{
    // ============== TEST ==================
    //Graph<int> graphe({ 10, 20, 30, 40 });

    //// 1. Le graphe commence avec quatre sommets et aucune liaison.
    //assert(graphe.n() == 4);
    //assert(graphe.e() == 0);
    //assert(graphe.sommet(0) == 10);
    //assert(graphe.sommet(3) == 40);
    //assert(graphe.first(0) == graphe.n());

    //// 2. Ajoute les voisins de 0 dans le désordre.
    //graphe.setEdge(0, 2, 80.0);
    //graphe.setEdge(0, 1, 70.5);

    //assert(graphe.e() == 2);
    //assert(graphe.isEdge(0, 1));
    //assert(graphe.weight(0, 1) == 70.5);
    //assert(!graphe.isEdge(1, 0));
    //assert(graphe.weight(1, 0) == 0.0);

    //// 3. Les voisins de 0 sont parcourus dans l'ordre des indices.
    //assert(graphe.first(0) == 1);
    //assert(graphe.next(0, 1) == 2);
    //assert(graphe.next(0, 2) == graphe.n());
    //assert(graphe.first(3) == graphe.n()); // Sommet isolé.

    //// 4. Ajoute la liaison de retour.
    //graphe.setEdge(1, 0, 70.5);
    //assert(graphe.e() == 3);
    //assert(graphe.isEdge(1, 0));
    //assert(graphe.weight(1, 0) == 70.5);

    //// 5. Modifier une liaison existante ne crée pas de doublon.
    //graphe.setEdge(0, 1, 60.25);
    //assert(graphe.e() == 3);
    //assert(graphe.weight(0, 1) == 60.25);
    //assert(graphe.weight(1, 0) == 70.5);

    //// 6. Les marques commencent à zéro et sont propres à chaque sommet.
    //for (int i = 0; i < graphe.n(); ++i) {
    //    assert(graphe.getMark(i) == 0);
    //}
    //graphe.setMark(2, 1);
    //assert(graphe.getMark(2) == 1);
    //assert(graphe.getMark(0) == 0);

    //// 7. Retire une liaison, puis essaie de la retirer une deuxième fois.
    //graphe.delEdge(0, 1);
    //assert(!graphe.isEdge(0, 1));
    //assert(graphe.isEdge(1, 0));
    //assert(graphe.e() == 2);
    //assert(graphe.first(0) == 2);

    //graphe.delEdge(0, 1);
    //assert(graphe.e() == 2);

    //// 8. Un indice invalide est détecté par sommet().
    //bool indiceInvalideDetecte = false;
    //try {
    //    graphe.sommet(4);
    //}
    //catch (const std::out_of_range&) {
    //    indiceInvalideDetecte = true;
    //}
    //assert(indiceInvalideDetecte);

    //std::cout << "Tous les tests du graphe ont reussi.\n";
}