#include "DFS.h"
#include <iostream>

using namespace std;

// Constructor que inicializa el objeto DFS
DFS::DFS() {}

// Método para agregar una arista entre los nodos u y v
void DFS::addEdge(int u, int v) {
    // Asegurarse de que la lista de adyacencia tenga suficiente tamaño
    if (u >= adjList.size() || v >= adjList.size()) {
        adjList.resize(std::max(u, v) + 1);
    }
    adjList[u].push_back(v); // Agregar v a la lista de adyacencia de u
    adjList[v].push_back(u); // Agregar u a la lista de adyacencia de v (para grafos no dirigidos)
}

// Método para ejecutar la búsqueda en profundidad desde el nodo 0
void DFS::execute() {
    visited.assign(adjList.size(), false); // Inicializa el vector de nodos visitados
    while (!traversalStack.empty()) traversalStack.pop(); // Limpia la pila
    dfs(0); // Comienza la búsqueda desde el nodo 0
}

// Método recursivo para realizar la búsqueda en profundidad desde el nodo v
void DFS::dfs(int v) {
    visited[v] = true; // Marca el nodo como visitado
    traversalStack.push(v); // Agrega el nodo a la pila
    for (int u : adjList[v]) { // Recorre los nodos adyacentes a v
        if (!visited[u]) { // Si un nodo adyacente no ha sido visitado
            dfs(u); // Llama recursivamente al método dfs
        }
    }
}

// Método para renderizar los nodos visitados en una ventana SFML
void DFS::render(sf::RenderWindow& window) {
    window.clear(sf::Color::White); // Limpia la ventana con un fondo blanco

    // Cargar la fuente para mostrar texto
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/DejaVuSans.ttf")) {
        cerr << "Failed to load font DejaVuSans.ttf" << std::endl;
        return;
    }

    int y = 50; // Posición inicial en el eje Y para los textos
    while (!traversalStack.empty()) { // Itera sobre los nodos visitados en la pila
        int v = traversalStack.top(); // Obtiene el nodo en la parte superior de la pila
        traversalStack.pop(); // Elimina el nodo de la pila

        // Crear el texto que muestra el nodo visitado
        sf::Text text("Visited node: " + to_string(v), font, 24);
        text.setPosition(50, y); // Posiciona el texto en la ventana
        text.setFillColor(sf::Color::Black); // Color del texto
        window.draw(text);
        y += 30; // Desplaza el texto hacia abajo para el siguiente nodo
    }

    window.display(); // Actualiza la ventana para mostrar los cambios
}
