#include "Dijkstra.h"
#include <iostream>
using namespace std;

Dijkstra::Dijkstra() {}

void Dijkstra::addEdge(int u, int v, int weight) {
    adjList[u].push_back({v, weight});
    adjList[v].push_back({u, weight}); // Grafos sin dirección
}

void Dijkstra::findShortestPath(int startNode, sf::RenderWindow& window) {
    unordered_map<int, int> distances;
    unordered_map<int, bool> visited;

    // Inicializa distancias al infinito
    for (auto& node : adjList) {
        distances[node.first] = numeric_limits<int>::max();
    }
    distances[startNode] = 0;

    // Min-heap to get the next closest node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, startNode}); // {Distance, Node}

    while (!pq.empty()) {
        int currentDistance = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (visited[currentNode]) continue;
        visited[currentNode] = true;

        // Update distances for neighbors
        for (auto& neighbor : adjList[currentNode]) {
            int nextNode = neighbor.first;
            int edgeWeight = neighbor.second;

            if (!visited[nextNode] && currentDistance + edgeWeight < distances[nextNode]) {
                distances[nextNode] = currentDistance + edgeWeight;
                pq.push({distances[nextNode], nextNode});
            }
        }

        // Render the graph after processing each node
        renderGraph(window, distances, currentNode);
    }
}

void Dijkstra::renderGraph(sf::RenderWindow& window, const unordered_map<int, int>& distances, int currentNode) {
    window.clear();

     sf::Font font;
    if (!font.loadFromFile("assets/fonts/DejaVuSans.ttf")) {
        cerr << "Failed to load font DejaVuSans.ttf" << endl;
        return;
    }

    // Dibujamos los nodos y los bordes
    for (auto& node : adjList) {
        int x = node.first * 50 + 100; // Example x-coordinate
        int y = 200;                  // Example y-coordinate

        // Dibujamos los bordes
        for (auto& neighbor : node.second) {
            int neighborX = neighbor.first * 50 + 100;
            int neighborY = 200;
            sf::Vertex line[] = {sf::Vertex(sf::Vector2f(x, y), sf::Color::White), sf::Vertex(sf::Vector2f(neighborX, neighborY), sf::Color::White)};
            window.draw(line, 2, sf::Lines);
        }

        // Dibujamos los nodos
        sf::CircleShape circle(20);
        circle.setFillColor(node.first == currentNode ? sf::Color::Green : sf::Color::Blue);
        circle.setPosition(x - 20, y - 20);
        window.draw(circle);

        // Dibujamos las distancias
        sf::Text distanceText;
        sf::Font font;
        font.loadFromFile("arial.ttf");
        distanceText.setFont(font);
        distanceText.setString(to_string(distances.at(node.first) == numeric_limits<int>::max() ? -1 : distances.at(node.first)));
        distanceText.setCharacterSize(15);
        distanceText.setFillColor(sf::Color::White);
        distanceText.setPosition(x - 10, y - 10);
        window.draw(distanceText);
    }

    window.display();
}
