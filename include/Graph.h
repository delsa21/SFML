#ifndef GRAPH_H
#define GRAPH_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph {
public:
    void addEdge(int u, int v);
    void bfs(int startNode, sf::RenderWindow& window);
    void dfs(int startNode, sf::RenderWindow& window);

private:
    unordered_map<int, vector<int>> adjList;
    void renderGraph(sf::RenderWindow& window, vector<int>& visitedNodes);
};

#endif
