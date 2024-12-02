#include "BinarySearch.h"

BinarySearch::BinarySearch(const vector<int>& data) : array(data), left(0), right(data.size() - 1), found(false), targetIndex(-1) {}

void BinarySearch::search(int target) {
    while (left <= right) {
        mid = (left + right) / 2;
        if (array[mid] == target) {
            targetIndex = mid;
            found = true;
            break;
        } else if (array[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
}

void BinarySearch::render(sf::RenderWindow& window) {
    float barWidth = window.getSize().x / array.size();
    for (int i = 0; i < array.size(); ++i) {
        sf::RectangleShape bar(sf::Vector2f(barWidth - 2, array[i] * 5));
        bar.setPosition(i * barWidth, window.getSize().y - array[i] * 5);

        if (i == mid) bar.setFillColor(sf::Color::Red);
        else if (i == targetIndex) bar.setFillColor(sf::Color::Green);
        else bar.setFillColor(sf::Color::White);

        window.draw(bar);
    }
}
