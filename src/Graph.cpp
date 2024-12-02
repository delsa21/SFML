#include "Graph.h"

void Graph::addEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u); // For undirected graph
}

void Graph::bfs(int startNode, sf::RenderWindow& window) {
    vector<int> visitedNodes;
    unordered_map<int, bool> visited;
    queue<int> q;
    q.push(startNode);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (!visited[node]) {
            visited[node] = true;
            visitedNodes.push_back(node);

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                }
            }

            renderGraph(window, visitedNodes);
        }
    }
}

void Graph::dfs(int startNode, sf::RenderWindow& window) {
    vector<int> visitedNodes;
    unordered_map<int, bool> visited;
    stack<int> s;
    s.push(startNode);

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            visited[node] = true;
            visitedNodes.push_back(node);

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }

            renderGraph(window, visitedNodes);
        }
    }
}

void Graph::renderGraph(sf::RenderWindow& window, vector<int>& visitedNodes) {
    window.clear();
    // Visualize the graph based on visitedNodes
    window.display();
}
