#include "BubbleSort.h"
#include <iostream>

BubbleSort::BubbleSort(const vector<int>& data) : array(data), currentIndex(0), sorted(false) {}

void BubbleSort::sort() {
    if (sorted) return;

    bool swapped = false;
    for (int i = 0; i < array.size() - 1 - currentIndex; ++i) {
        if (array[i] > array[i + 1]) {
            swap(array[i], array[i + 1]);
            swapped = true;
        }
    }

    if (!swapped) sorted = true;
    ++currentIndex;
}

void BubbleSort::render(sf::RenderWindow& window) {
     sf::Font font;
    if (!font.loadFromFile("assets/fonts/DejaVuSans.ttf")) {
        cerr << "Failed to load font DejaVuSans.ttf" << endl;
        return;
    }
    float barWidth = window.getSize().x / array.size();
    for (int i = 0; i < array.size(); ++i) {
        sf::RectangleShape bar(sf::Vector2f(barWidth - 2, array[i] * 5));
        bar.setPosition(i * barWidth, window.getSize().y - array[i] * 5);

        if (i == currentIndex || i == currentIndex - 1) bar.setFillColor(sf::Color::Red);
        else bar.setFillColor(sf::Color::White);

        window.draw(bar);
    }
}
