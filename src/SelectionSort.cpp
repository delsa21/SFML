#include "SelectionSort.h"

SelectionSort::SelectionSort(const std::vector<int>& data) : array(data), currentIndex(0), minIndex(0), sorted(false) {}

void SelectionSort::sort() {
    if (currentIndex >= array.size() - 1) {
        sorted = true;
        return;
    }

    minIndex = currentIndex;
    for (int j = currentIndex + 1; j < array.size(); ++j) {
        if (array[j] < array[minIndex]) {
            minIndex = j;
        }
    }

    std::swap(array[currentIndex], array[minIndex]);
    ++currentIndex;
}

void SelectionSort::render(sf::RenderWindow& window) {
    float barWidth = window.getSize().x / array.size();
    for (int i = 0; i < array.size(); ++i) {
        sf::RectangleShape bar(sf::Vector2f(barWidth - 2, array[i] * 5));
        bar.setPosition(i * barWidth, window.getSize().y - array[i] * 5);

        if (i == currentIndex) bar.setFillColor(sf::Color::Red);
        else if (i == minIndex) bar.setFillColor(sf::Color::Blue);
        else bar.setFillColor(sf::Color::White);

        window.draw(bar);
    }
}
