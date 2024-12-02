#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <SFML/Graphics.hpp>
#include <vector>

class InsertionSort {
public:
    InsertionSort(const std::vector<int>& data);
    void sort();
    void render(sf::RenderWindow& window);

private:
    std::vector<int> array;
    int currentIndex;
    int keyIndex;
    bool sorted;
};

#endif
