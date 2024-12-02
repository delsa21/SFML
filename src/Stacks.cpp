#include "Stacks.h"

Stack::Stack() : maxSize(10) {}

void Stack::push(int value) {
    if (stack.size() < maxSize) {
        stack.push_back(value);
    }
}

void Stack::pop() {
    if (!stack.empty()) {
        stack.pop_back();
    }
}

void Stack::render(sf::RenderWindow& window) {
    float boxWidth = window.getSize().x / (maxSize + 2);
    float boxHeight = 40.0f;

    for (int i = 0; i < stack.size(); ++i) {
        sf::RectangleShape box(sf::Vector2f(boxWidth, boxHeight));
        box.setPosition(window.getSize().x / 2 - boxWidth / 2, window.getSize().y - (i + 1) * (boxHeight + 5));
        box.setFillColor(sf::Color::Blue);

        window.draw(box);

        sf::Text valueText;
        sf::Font font;
        font.loadFromFile("arial.ttf");
        valueText.setFont(font);
        valueText.setString(to_string(stack[i]));
        valueText.setCharacterSize(20);
        valueText.setFillColor(sf::Color::White);
        valueText.setPosition(box.getPosition().x + boxWidth / 4, box.getPosition().y + 5);
        window.draw(valueText);
    }
}
