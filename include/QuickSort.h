#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

class QuickSort {
public:
    QuickSort(const vector<int>& data);
    void sort();
    void render(sf::RenderWindow& window);

private:
    vector<int> array;
    bool sorted;

    void quickSort(int low, int high);
    int partition(int low, int high);
    void renderState(sf::RenderWindow& window, int low, int high, int pivotIndex);
};

#endif
