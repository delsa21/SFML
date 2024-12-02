#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

// Clase que representa el algoritmo de Dijkstra para encontrar caminos más cortos en un grafo ponderado
class Dijkstra {
public:
    Dijkstra(); // Constructor para inicializar la clase

    // Agrega una arista (conexión) entre dos nodos con un peso asociado
    void addEdge(int u, int v, int weight);

    // Encuentra el camino más corto desde un nodo inicial a todos los demás nodos
    // y visualiza el progreso en una ventana SFML
    void findShortestPath(int startNode, sf::RenderWindow& window);

private:
    unordered_map<int, vector<pair<int, int>>> adjList; // Lista de adyacencia para representar el grafo
    // Cada nodo está asociado a un vector de pares (nodo vecino, peso de la arista)

    // Renderiza el grafo y las distancias calculadas en la ventana SFML
    void renderGraph(sf::RenderWindow& window, const unordered_map<int, int>& distances, int currentNode);
};

#endif
