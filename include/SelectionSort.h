#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <SFML/Graphics.hpp>
#include <vector>

class SelectionSort {
public:
    SelectionSort(const std::vector<int>& data);
    void sort();
    void render(sf::RenderWindow& window);

private:
    std::vector<int> array;
    int currentIndex;
    int minIndex;
    bool sorted;
};

#endif
