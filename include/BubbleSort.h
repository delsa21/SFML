#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

class BubbleSort {
public:
    BubbleSort(const vector<int>& data);
    void sort();
    void render(sf::RenderWindow& window);

private:
    vector<int> array;
    int currentIndex;
    bool sorted;
};

#endif
