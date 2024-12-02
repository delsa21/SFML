#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

class MergeSort {
public:
    MergeSort(const std::vector<int>& data);
    void sort();
    void render(sf::RenderWindow& window);

private:
    void mergeSort(int left, int right);
    void merge(int left, int mid, int right);

    vector<int> array;
    vector<int> tempArray;
    bool sorted;
    int currentLeft, currentRight, midPoint;
};

#endif
