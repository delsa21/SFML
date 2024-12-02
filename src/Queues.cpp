#include "Queues.h"

Queue::Queue() : maxSize(10) {}

void Queue::enqueue(int value) {
    if (queue.size() < maxSize) {
        queue.push_back(value);
    }
}

void Queue::dequeue() {
    if (!queue.empty()) {
        queue.pop_front();
    }
}

void Queue::render(sf::RenderWindow& window) {
    float boxWidth = 60.0f;
    float boxHeight = 40.0f;

    for (int i = 0; i < queue.size(); ++i) {
        sf::RectangleShape box(sf::Vector2f(boxWidth, boxHeight));
        box.setPosition(100 + i * (boxWidth + 5), window.getSize().y / 2 - boxHeight / 2);
        box.setFillColor(sf::Color::Green);

        window.draw(box);

        sf::Text valueText;
        sf::Font font;
        font.loadFromFile("arial.ttf");
        valueText.setFont(font);
        valueText.setString(to_string(queue[i]));
        valueText.setCharacterSize(20);
        valueText.setFillColor(sf::Color::White);
        valueText.setPosition(box.getPosition().x + boxWidth / 4, box.getPosition().y + 5);
        window.draw(valueText);
    }
}
