#include "QuickSort.h"

QuickSort::QuickSort(const vector<int>& data) : array(data), sorted(false) {}

void QuickSort::sort() {
    if (!sorted) {
        quickSort(0, array.size() - 1);
        sorted = true;
    }
}

void QuickSort::quickSort(int low, int high) {
    if (low < high) {
        int pivotIndex = partition(low, high);
        quickSort(low, pivotIndex - 1);
        quickSort(pivotIndex + 1, high);
    }
}

int QuickSort::partition(int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (array[j] <= pivot) {
            ++i;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return i + 1;
}

void QuickSort::render(sf::RenderWindow& window) {
    float barWidth = window.getSize().x / array.size();
    static int step = 0;

    if (step == 0) quickSort(0, array.size() - 1);

    window.clear();
    for (int i = 0; i < array.size(); ++i) {
        sf::RectangleShape bar(sf::Vector2f(barWidth - 2, array[i] * 5));
        bar.setPosition(i * barWidth, window.getSize().y - array[i] * 5);

        bar.setFillColor(sf::Color::White);
        window.draw(bar);
    }
    window.display();

    ++step;
}
