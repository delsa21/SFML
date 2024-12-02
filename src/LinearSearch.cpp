#include "LinearSearch.h"

LinearSearch::LinearSearch(const vector<int>& data) : array(data), currentIndex(0), found(false), targetIndex(-1) {}

void LinearSearch::search(int target) {
    for (currentIndex = 0; currentIndex < array.size(); ++currentIndex) {
        if (array[currentIndex] == target) {
            targetIndex = currentIndex;
            found = true;
            break;
        }
    }
}

void LinearSearch::render(sf::RenderWindow& window) {
    float barWidth = window.getSize().x / array.size();
    for (int i = 0; i < array.size(); ++i) {
        sf::RectangleShape bar(sf::Vector2f(barWidth - 2, array[i] * 5));
        bar.setPosition(i * barWidth, window.getSize().y - array[i] * 5);

        if (i == currentIndex) bar.setFillColor(sf::Color::Red);
        else if (i == targetIndex) bar.setFillColor(sf::Color::Green);
        else bar.setFillColor(sf::Color::White);

        window.draw(bar);
    }
}
