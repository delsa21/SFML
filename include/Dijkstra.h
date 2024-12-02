#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

class Dijkstra {
public:
    Dijkstra();
    void addEdge(int u, int v, int weight);
    void findShortestPath(int startNode, sf::RenderWindow& window);

private:
    unordered_map<int, vector<pair<int, int>>> adjList; // Node -> [(Neighbor, Weight)]
    void renderGraph(sf::RenderWindow& window, const unordered_map<int, int>& distances, int currentNode);
};

#endif
