#ifndef BFS_H
#define BFS_H

#include <vector>
#include <queue>
#include <SFML/Graphics.hpp>

using namespace std;

// Clase que representa el algoritmo de Búsqueda en Anchura (BFS)
class BFS {
public:
    BFS(); // Constructor para inicializar la clase

    // Agrega una arista al grafo, conectando los nodos u y v
    void addEdge(int u, int v);

    // Ejecuta el algoritmo BFS
    void execute();

    // Renderiza el grafo y la ejecución del BFS en una ventana SFML
    void render(sf::RenderWindow& window);

private:
    vector<vector<int>> adjList; // Lista de adyacencia para representar el grafo
    vector<bool> visited; // Vector para rastrear los nodos visitados
    queue<int> traversalQueue; // Cola utilizada para la ejecución del BFS

    // Función recursiva que realiza BFS a partir del nodo v
    void bfs(int v);
};

#endif // BFS_H
