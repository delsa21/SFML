#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <queue>
#include <stack>
#include <SFML/Graphics.hpp>

using namespace std;

// Clase que representa un grafo y permite realizar búsquedas (DFS y BFS)
class Graph {
public:
    Graph(); // Constructor para inicializar el grafo

    // Método para agregar una arista entre dos nodos (u y v)
    void addEdge(int u, int v);

    // Ejecuta el algoritmo de búsqueda en profundidad (DFS) desde el nodo inicial
    void dfs(int startNode);

    // Ejecuta el algoritmo de búsqueda en anchura (BFS) desde el nodo inicial
    void bfs(int startNode);

    // Renderiza el grafo y el proceso de búsqueda (DFS o BFS) en una ventana SFML
    void render(sf::RenderWindow& window);

private:
    vector<vector<int>> adjList; // Lista de adyacencia que representa las conexiones del grafo
    vector<bool> visitedDFS; // Vector que indica si un nodo ha sido visitado en DFS
    vector<bool> visitedBFS; // Vector que indica si un nodo ha sido visitado en BFS
    stack<int> traversalStack; // Pila para manejar la búsqueda en profundidad (DFS)
    queue<int> traversalQueue; // Cola para manejar la búsqueda en anchura (BFS)

    // Método privado que realiza DFS desde un nodo específico
    void dfsVisit(int v);
};

#endif // GRAPH_H
