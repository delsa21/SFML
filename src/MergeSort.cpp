#include "MergeSort.h"

MergeSort::MergeSort(const std::vector<int>& data) 
    : array(data), tempArray(data.size()), sorted(false), currentLeft(0), currentRight(data.size() - 1), midPoint(0) {}

void MergeSort::sort() {
    if (!sorted) {
        mergeSort(0, array.size() - 1);
        sorted = true;
    }
}

void MergeSort::mergeSort(int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}

void MergeSort::merge(int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (array[i] <= array[j]) {
            tempArray[k++] = array[i++];
        } else {
            tempArray[k++] = array[j++];
        }
    }

    while (i <= mid) tempArray[k++] = array[i++];
    while (j <= right) tempArray[k++] = array[j++];

    for (int idx = left; idx <= right; ++idx) {
        array[idx] = tempArray[idx];
    }

    currentLeft = left;
    midPoint = mid;
    currentRight = right;
}

void MergeSort::render(sf::RenderWindow& window) {
    float barWidth = window.getSize().x / array.size();
    for (int i = 0; i < array.size(); ++i) {
        sf::RectangleShape bar(sf::Vector2f(barWidth - 2, array[i] * 5));
        bar.setPosition(i * barWidth, window.getSize().y - array[i] * 5);

        if (i >= currentLeft && i <= currentRight) bar.setFillColor(sf::Color::Blue);
        else bar.setFillColor(sf::Color::White);

        window.draw(bar);
    }
}
