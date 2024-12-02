#ifndef BFS_H
#define BFS_H

#include <vector>
#include <queue>
#include <SFML/Graphics.hpp>

class BFS {
public:
    BFS();
    void addEdge(int u, int v);
    void execute();
    void render(sf::RenderWindow& window);

private:
    std::vector<std::vector<int>> adjList;
    std::vector<bool> visited;
    std::queue<int> traversalQueue;
    void bfs(int v);
};

#endif // BFS_H
