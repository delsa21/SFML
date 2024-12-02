#include "Graph.h"
#include <iostream>

// Constructor para inicializar la clase Graph
Graph::Graph() {}

// Método para agregar una arista entre los nodos u y v
void Graph::addEdge(int u, int v) {
    // Asegura que la lista de adyacencia tenga suficiente tamaño
    if (u >= adjList.size() || v >= adjList.size()) {
        adjList.resize(std::max(u, v) + 1);
    }
    adjList[u].push_back(v); // Agrega v a la lista de adyacencia de u
    adjList[v].push_back(u); // Agrega u a la lista de adyacencia de v (para grafos no dirigidos)
}

// Método para realizar DFS desde el nodo inicial
void Graph::dfs(int startNode) {
    visitedDFS.assign(adjList.size(), false); // Inicializa los nodos como no visitados
    while (!traversalStack.empty()) traversalStack.pop(); // Limpia la pila
    dfsVisit(startNode); // Llama al método recursivo para visitar los nodos
}

// Método recursivo para visitar nodos durante DFS
void Graph::dfsVisit(int v) {
    visitedDFS[v] = true; // Marca el nodo como visitado
    traversalStack.push(v); // Agrega el nodo a la pila de recorrido
    for (int u : adjList[v]) { // Itera sobre los nodos adyacentes
        if (!visitedDFS[u]) { // Si un nodo no ha sido visitado
            dfsVisit(u); // Llama recursivamente al método para el nodo vecino
        }
    }
}

// Método para realizar BFS desde el nodo inicial
void Graph::bfs(int startNode) {
    visitedBFS.assign(adjList.size(), false); // Inicializa los nodos como no visitados
    while (!traversalQueue.empty()) traversalQueue.pop(); // Limpia la cola
    traversalQueue.push(startNode); // Agrega el nodo inicial a la cola
    visitedBFS[startNode] = true; // Marca el nodo inicial como visitado

    while (!traversalQueue.empty()) {
        int v = traversalQueue.front(); // Obtiene el nodo en la parte frontal de la cola
        traversalQueue.pop(); // Elimina el nodo de la cola
        for (int u : adjList[v]) { // Itera sobre los nodos adyacentes
            if (!visitedBFS[u]) { // Si el nodo no ha sido visitado
                visitedBFS[u] = true; // Lo marca como visitado
                traversalQueue.push(u); // Lo agrega a la cola
            }
        }
    }
}

// Método para renderizar los resultados de DFS y BFS en una ventana SFML
void Graph::render(sf::RenderWindow& window) {
    window.clear(sf::Color::White); // Limpia la ventana con un fondo blanco

    // Carga la fuente para mostrar texto
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/DejaVuSans.ttf")) {
        std::cerr << "Failed to load font DejaVuSans.ttf" << std::endl;
        return;
    }

    // Renderiza los nodos visitados por DFS
    int yDFS = 50; // Posición inicial para los resultados de DFS
    std::stack<int> tempStack = traversalStack; // Crea una copia temporal de la pila
    while (!tempStack.empty()) {
        int v = tempStack.top(); // Obtiene el nodo en la parte superior de la pila
        tempStack.pop(); // Elimina el nodo de la pila temporal

        sf::Text text("DFS visited node: " + std::to_string(v), font, 24);
        text.setPosition(50, yDFS); // Posiciona el texto en la ventana
        text.setFillColor(sf::Color::Black); // Color del texto
        window.draw(text);
        yDFS += 30; // Ajusta la posición para el siguiente nodo
    }

    // Renderiza los nodos visitados por BFS
    int yBFS = yDFS + 50; // Posición inicial para los resultados de BFS
    std::queue<int> tempQueue = traversalQueue; // Crea una copia temporal de la cola
    while (!tempQueue.empty()) {
        int v = tempQueue.front(); // Obtiene el nodo en la parte frontal de la cola
        tempQueue.pop(); // Elimina el nodo de la cola temporal

        sf::Text text("BFS visited node: " + std::to_string(v), font, 24);
        text.setPosition(50, yBFS); // Posiciona el texto en la ventana
        text.setFillColor(sf::Color::Black); // Color del texto
        window.draw(text);
        yBFS += 30; // Ajusta la posición para el siguiente nodo
    }

    window.display(); // Actualiza la ventana para mostrar los cambios
}
