#ifndef DFS_H
#define DFS_H

#include <vector>
#include <stack>
#include <SFML/Graphics.hpp>
using namespace std;

// Clase que representa el algoritmo de Búsqueda en Profundidad (DFS)
class DFS {
public:
    DFS(); // Constructor para inicializar la clase

    // Agrega una arista (conexión) entre los nodos u y v en el grafo
    void addEdge(int u, int v);

    // Ejecuta el algoritmo DFS
    void execute();

    // Renderiza el grafo y la ejecución del DFS en una ventana SFML
    void render(sf::RenderWindow& window);

private:
    vector<vector<int>> adjList; // Lista de adyacencia para representar el grafo
    vector<bool> visited; // Vector que indica qué nodos han sido visitados
    stack<int> traversalStack; // Pila utilizada para manejar la exploración del grafo

    // Función recursiva que realiza DFS a partir del nodo v
    void dfs(int v);
};

#endif // DFS_H
