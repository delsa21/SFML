#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() {}

void LinkedList::insert(int position, int value) {
    if (position >= 0 && position <= list.size()) {
        list.insert(list.begin() + position, value);
    }
}

void LinkedList::remove(int position) {
    if (position >= 0 && position < list.size()) {
        list.erase(list.begin() + position);
    }
}

void LinkedList::render(sf::RenderWindow& window) {
     sf::Font font;
    if (!font.loadFromFile("assets/fonts/DejaVuSans.ttf")) {
        cerr << "Failed to load font DejaVuSans.ttf" << endl;
        return;
    }
    float boxWidth = 80.0f;
    float boxHeight = 40.0f;

    for (int i = 0; i < list.size(); ++i) {
        sf::RectangleShape box(sf::Vector2f(boxWidth, boxHeight));
        box.setPosition(100 + i * (boxWidth + 10), window.getSize().y / 2 - boxHeight / 2);
        box.setFillColor(sf::Color::Yellow);

        window.draw(box);

        sf::Text valueText;
        sf::Font font;
        font.loadFromFile("arial.ttf");
        valueText.setFont(font);
        valueText.setString(to_string(list[i]));
        valueText.setCharacterSize(20);
        valueText.setFillColor(sf::Color::Black);
        valueText.setPosition(box.getPosition().x + boxWidth / 4, box.getPosition().y + 5);
        window.draw(valueText);

        if (i < list.size() - 1) {
            sf::RectangleShape arrow(sf::Vector2f(30, 5));
            arrow.setPosition(100 + i * (boxWidth + 10) + boxWidth, window.getSize().y / 2 - 2);
            arrow.setFillColor(sf::Color::Black);
            window.draw(arrow);
        }
    }
}
