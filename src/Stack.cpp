#include "Stack.h"
#include <iostream>

Stack::Stack() {}

void Stack::push(int value) {
    data.push_back(value);
}

void Stack::pop() {
    if (!data.empty()) {
        data.pop_back();
    } else {
        std::cerr << "Stack is empty, cannot pop." << std::endl;
    }
}

int Stack::top() const {
    if (!data.empty()) {
        return data.back();
    } else {
        std::cerr << "Stack is empty, cannot top." << std::endl;
        return -1; // Valor de error
    }
}

bool Stack::isEmpty() const {
    return data.empty();
}

void Stack::render(sf::RenderWindow& window) {
    window.clear(sf::Color::White);

    sf::Font font;
    if (!font.loadFromFile("assets/fonts/DejaVuSans.ttf")) {
        std::cerr << "Failed to load font DejaVuSans.ttf" << std::endl;
        return;
    }

    for (int i = 0; i < data.size(); i++) {
        sf::Text text(std::to_string(data[i]), font, 24);
        text.setPosition(50, 50 + i * 30);
        text.setFillColor(sf::Color::Black);
        window.draw(text);
    }

    window.display();
}
