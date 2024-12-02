#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

class LinearSearch {
public:
    LinearSearch(const vector<int>& data);
    void search(int target);
    void render(sf::RenderWindow& window);

private:
    vector<int> array;
    int targetIndex;
    int currentIndex;
    bool found;
};

#endif
