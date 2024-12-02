#include "BFS.h"
#include <iostream>

using namespace std;

BFS::BFS() {}

void BFS::addEdge(int u, int v) {
    if (u >= adjList.size() || v >= adjList.size()) {
        adjList.resize(std::max(u, v) + 1);
    }
    adjList[u].push_back(v);
    adjList[v].push_back(u); // Para grafos no dirigidos
}

void BFS::execute() {
    visited.assign(adjList.size(), false);
    while (!traversalQueue.empty()) traversalQueue.pop();
    bfs(0); // Suponiendo que el nodo de inicio es 0
}

void BFS::bfs(int v) {
    visited[v] = true;
    traversalQueue.push(v);
    while (!traversalQueue.empty()) {
        int u = traversalQueue.front();
        traversalQueue.pop();
        for (int w : adjList[u]) {
            if (!visited[w]) {
                visited[w] = true;
                traversalQueue.push(w);
            }
        }
    }
}

void BFS::render(sf::RenderWindow& window) {
    window.clear(sf::Color::White);

    sf::Font font;
    if (!font.loadFromFile("assets/fonts/DejaVuSans.ttf")) {
        cerr << "Failed to load font DejaVuSans.ttf" << endl;
        return;
    }

    int y = 50;
    while (!traversalQueue.empty()) {
        int v = traversalQueue.front();
        traversalQueue.pop();
        sf::Text text("Visited node: " + std::to_string(v), font, 24);
        text.setPosition(50, y);
        text.setFillColor(sf::Color::Black);
        window.draw(text);
        y += 30;
    }

    window.display();
}
