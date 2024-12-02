#include "InsertionSort.h"

InsertionSort::InsertionSort(const std::vector<int>& data) : array(data), currentIndex(1), keyIndex(0), sorted(false) {}

void InsertionSort::sort() {
    if (currentIndex >= array.size()) {
        sorted = true;
        return;
    }

    int key = array[currentIndex];
    keyIndex = currentIndex - 1;

    while (keyIndex >= 0 && array[keyIndex] > key) {
        array[keyIndex + 1] = array[keyIndex];
        --keyIndex;
    }

    array[keyIndex + 1] = key;
    ++currentIndex;
}

void InsertionSort::render(sf::RenderWindow& window) {
    float barWidth = window.getSize().x / array.size();
    for (int i = 0; i < array.size(); ++i) {
        sf::RectangleShape bar(sf::Vector2f(barWidth - 2, array[i] * 5));
        bar.setPosition(i * barWidth, window.getSize().y - array[i] * 5);

        if (i == currentIndex) bar.setFillColor(sf::Color::Red);
        else if (i == keyIndex + 1) bar.setFillColor(sf::Color::Blue);
        else bar.setFillColor(sf::Color::White);

        window.draw(bar);
    }
}
