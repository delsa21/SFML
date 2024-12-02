#include "BFS.h"
#include <iostream>

using namespace std;

// Constructor para inicializar la clase BFS
BFS::BFS() {}

// Agrega una arista entre los nodos u y v
void BFS::addEdge(int u, int v) {
    // Si los nodos u o v no están dentro del tamaño actual de la lista de adyacencia, se redimensiona
    if (u >= adjList.size() || v >= adjList.size()) {
        adjList.resize(std::max(u, v) + 1);
    }
    adjList[u].push_back(v); // Agrega v a la lista de adyacencia de u
    adjList[v].push_back(u); // Agrega u a la lista de adyacencia de v (para grafos no dirigidos)
}

// Ejecuta el algoritmo BFS desde el nodo 0
void BFS::execute() {
    visited.assign(adjList.size(), false); // Inicializa el vector de nodos visitados
    while (!traversalQueue.empty()) traversalQueue.pop(); // Limpia la cola
    bfs(0); // Comienza la búsqueda desde el nodo 0
}

// Realiza la búsqueda en anchura desde el nodo v
void BFS::bfs(int v) {
    visited[v] = true; // Marca el nodo v como visitado
    traversalQueue.push(v); // Encola el nodo inicial
    while (!traversalQueue.empty()) {
        int u = traversalQueue.front(); // Obtiene el nodo al frente de la cola
        traversalQueue.pop(); // Lo elimina de la cola
        for (int w : adjList[u]) { // Recorre los nodos adyacentes a u
            if (!visited[w]) { // Si el nodo no ha sido visitado
                visited[w] = true; // Lo marca como visitado
                traversalQueue.push(w); // Lo encola
            }
        }
    }
}

// Renderiza el resultado del BFS en una ventana SFML
void BFS::render(sf::RenderWindow& window) {
    window.clear(sf::Color::White); // Limpia la ventana con un fondo blanco

    // Carga la fuente para mostrar texto
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/DejaVuSans.ttf")) {
        cerr << "Failed to load font DejaVuSans.ttf" << endl;
        return;
    }

    int y = 50; // Posición inicial en el eje Y para los textos
    while (!traversalQueue.empty()) { // Itera sobre los nodos visitados en la cola
        int v = traversalQueue.front(); // Obtiene el nodo en la parte frontal de la cola
        traversalQueue.pop(); // Elimina el nodo de la cola

        // Muestra el nodo visitado en pantalla
        sf::Text text("Visited node: " + std::to_string(v), font, 24);
        text.setPosition(50, y); // Posición del texto en la ventana
        text.setFillColor(sf::Color::Black); // Color del texto
        window.draw(text);
        y += 30; // Desplaza el texto hacia abajo
    }

    window.display(); // Actualiza la ventana para mostrar los cambios
}
