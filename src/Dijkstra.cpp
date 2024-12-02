#include "Dijkstra.h"
#include <iostream>
using namespace std;

// Constructor de la clase Dijkstra
Dijkstra::Dijkstra() {}

// Método para agregar una arista entre dos nodos con un peso asociado
void Dijkstra::addEdge(int u, int v, int weight) {
    adjList[u].push_back({v, weight}); // Agrega el vecino v con su peso a la lista de adyacencia de u
    adjList[v].push_back({u, weight}); // Para grafos no dirigidos, agrega la conexión inversa
}

// Método para encontrar el camino más corto desde un nodo inicial y renderizar el grafo
void Dijkstra::findShortestPath(int startNode, sf::RenderWindow& window) {
    unordered_map<int, int> distances; // Almacena las distancias mínimas desde el nodo inicial
    unordered_map<int, bool> visited; // Rastrea los nodos ya procesados

    // Inicializa las distancias al infinito
    for (auto& node : adjList) {
        distances[node.first] = numeric_limits<int>::max();
    }
    distances[startNode] = 0; // La distancia al nodo inicial es 0

    // Min-heap (cola de prioridad) para seleccionar el nodo más cercano
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, startNode}); // {Distancia, Nodo}

    while (!pq.empty()) {
        int currentDistance = pq.top().first; // Distancia acumulada del nodo actual
        int currentNode = pq.top().second;   // Nodo actual
        pq.pop();

        // Si el nodo ya fue visitado, lo omitimos
        if (visited[currentNode]) continue;
        visited[currentNode] = true;

        // Actualiza las distancias para los vecinos del nodo actual
        for (auto& neighbor : adjList[currentNode]) {
            int nextNode = neighbor.first;      // Nodo vecino
            int edgeWeight = neighbor.second;   // Peso de la arista

            // Si encontramos un camino más corto hacia el vecino
            if (!visited[nextNode] && currentDistance + edgeWeight < distances[nextNode]) {
                distances[nextNode] = currentDistance + edgeWeight; // Actualiza la distancia
                pq.push({distances[nextNode], nextNode});           // Agrega el vecino a la cola de prioridad
            }
        }

        // Renderiza el grafo después de procesar cada nodo
        renderGraph(window, distances, currentNode);
    }
}

// Método para renderizar el grafo y mostrar las distancias
void Dijkstra::renderGraph(sf::RenderWindow& window, const unordered_map<int, int>& distances, int currentNode) {
    window.clear(); // Limpia la ventana

    sf::Font font;
    if (!font.loadFromFile("assets/fonts/DejaVuSans.ttf")) {
        cerr << "Failed to load font DejaVuSans.ttf" << endl;
        return;
    }

    // Dibuja los nodos y los bordes
    for (auto& node : adjList) {
        int x = node.first * 50 + 100; // Coordenada X (ejemplo)
        int y = 200;                  // Coordenada Y (ejemplo)

        // Dibuja los bordes hacia los nodos vecinos
        for (auto& neighbor : node.second) {
            int neighborX = neighbor.first * 50 + 100;
            int neighborY = 200;
            sf::Vertex line[] = {sf::Vertex(sf::Vector2f(x, y), sf::Color::White), sf::Vertex(sf::Vector2f(neighborX, neighborY), sf::Color::White)};
            window.draw(line, 2, sf::Lines);
        }

        // Dibuja el nodo actual
        sf::CircleShape circle(20);
        circle.setFillColor(node.first == currentNode ? sf::Color::Green : sf::Color::Blue); // Nodo actual en verde, otros en azul
        circle.setPosition(x - 20, y - 20);
        window.draw(circle);

        // Dibuja la distancia mínima desde el nodo inicial
        sf::Text distanceText;
        distanceText.setFont(font);
        distanceText.setString(to_string(distances.at(node.first) == numeric_limits<int>::max() ? -1 : distances.at(node.first)));
        distanceText.setCharacterSize(15);
        distanceText.setFillColor(sf::Color::White);
        distanceText.setPosition(x - 10, y - 10);
        window.draw(distanceText);
    }

    window.display(); // Actualiza la ventana
}
