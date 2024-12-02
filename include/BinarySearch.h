#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

class BinarySearch {
public:
    BinarySearch(const vector<int>& data);
    void search(int target);
    void render(sf::RenderWindow& window);

private:
    vector<int> array;
    int left, right, mid;
    int targetIndex;
    bool found;
};

#endif
