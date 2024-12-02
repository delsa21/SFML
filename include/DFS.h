
#ifndef DFS_H
#define DFS_H

#include <vector>
#include <stack>
#include <SFML/Graphics.hpp>
using namespace std;

class DFS {
public:
    DFS();
    void addEdge(int u, int v);
    void execute();
    void render(sf::RenderWindow& window);

private:
    vector<std::vector<int>> adjList;
    vector<bool> visited;
    stack<int> traversalStack;
    void dfs(int v);
};

#endif // DFS_H
