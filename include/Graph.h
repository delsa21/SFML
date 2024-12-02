#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <queue>
#include <stack>
#include <SFML/Graphics.hpp>

using namespace std;

class Graph {
public:
    Graph();
    void addEdge(int u, int v);
    void dfs(int startNode);
    void bfs(int startNode);
    void render(sf::RenderWindow& window);

private:
    vector<vector<int>> adjList;
    vector<bool> visitedDFS;
    vector<bool> visitedBFS;
    stack<int> traversalStack;
    queue<int> traversalQueue;
    void dfsVisit(int v);
};

#endif // GRAPH_H
