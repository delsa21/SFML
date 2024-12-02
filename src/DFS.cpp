#include "DFS.h"
#include <iostream>

using namespace std;

DFS::DFS() {}

void DFS::addEdge(int u, int v) {
    if (u >= adjList.size() || v >= adjList.size()) {
        adjList.resize(std::max(u, v) + 1);
    }
    adjList[u].push_back(v);
    adjList[v].push_back(u); // Para grafos no dirigidos
}

void DFS::execute() {
    visited.assign(adjList.size(), false);
    while (!traversalStack.empty()) traversalStack.pop();
    dfs(0); // Suponiendo que el nodo de inicio es 0
}

void DFS::dfs(int v) {
    visited[v] = true;
    traversalStack.push(v);
    for (int u : adjList[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

void DFS::render(sf::RenderWindow& window) {
    window.clear(sf::Color::White);

    sf::Font font;
    if (!font.loadFromFile("assets/fonts/DejaVuSans.ttf")) {
        cerr << "Failed to load font DejaVuSans.ttf" << std::endl;
        return;
    }

    int y = 50;
    while (!traversalStack.empty()) {
        int v = traversalStack.top();
        traversalStack.pop();
        sf :: Text text("Visited node: " + to_string(v), font, 24);
        text.setPosition(50, y);
        text.setFillColor(sf::Color::Black);
        window.draw(text);
        y += 30;
    }

    window.display();
}
