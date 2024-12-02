#include "Graph.h"
#include <iostream>

Graph::Graph() {}

void Graph::addEdge(int u, int v) {
    if (u >= adjList.size() || v >= adjList.size()) {
        adjList.resize(std::max(u, v) + 1);
    }
    adjList[u].push_back(v);
    adjList[v].push_back(u); // Para grafos no dirigidos
}

void Graph::dfs(int startNode) {
    visitedDFS.assign(adjList.size(), false);
    while (!traversalStack.empty()) traversalStack.pop();
    dfsVisit(startNode);
}

void Graph::dfsVisit(int v) {
    visitedDFS[v] = true;
    traversalStack.push(v);
    for (int u : adjList[v]) {
        if (!visitedDFS[u]) {
            dfsVisit(u);
        }
    }
}

void Graph::bfs(int startNode) {
    visitedBFS.assign(adjList.size(), false);
    while (!traversalQueue.empty()) traversalQueue.pop();
    traversalQueue.push(startNode);
    visitedBFS[startNode] = true;

    while (!traversalQueue.empty()) {
        int v = traversalQueue.front();
        traversalQueue.pop();
        for (int u : adjList[v]) {
            if (!visitedBFS[u]) {
                visitedBFS[u] = true;
                traversalQueue.push(u);
            }
        }
    }
}

void Graph::render(sf::RenderWindow& window) {
    window.clear(sf::Color::White);

    sf::Font font;
    if (!font.loadFromFile("assets/fonts/DejaVuSans.ttf")) {
        std::cerr << "Failed to load font DejaVuSans.ttf" << std::endl;
        return;
    }

    int yDFS = 50;
    std::stack<int> tempStack = traversalStack;
    while (!tempStack.empty()) {
        int v = tempStack.top();
        tempStack.pop();
        sf::Text text("DFS visited node: " + std::to_string(v), font, 24);
        text.setPosition(50, yDFS);
        text.setFillColor(sf::Color::Black);
        window.draw(text);
        yDFS += 30;
    }

    int yBFS = yDFS + 50;
    std::queue<int> tempQueue = traversalQueue;
    while (!tempQueue.empty()) {
        int v = tempQueue.front();
        tempQueue.pop();
        sf::Text text("BFS visited node: " + std::to_string(v), font, 24);
        text.setPosition(50, yBFS);
        text.setFillColor(sf::Color::Black);
        window.draw(text);
        yBFS += 30;
    }

    window.display();
}
