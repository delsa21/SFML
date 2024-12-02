#include "LinkedList.h"
#include <iostream>

using namespace std;

// Constructor que inicializa la lista enlazada
LinkedList::LinkedList() {}

// Método para insertar un valor en una posición específica
void LinkedList::insert(int position, int value) {
    // Verifica si la posición es válida antes de insertar
    if (position >= 0 && position <= list.size()) {
        list.insert(list.begin() + position, value); // Inserta el valor en la posición especificada
    }
}

// Método para eliminar un valor de una posición específica
void LinkedList::remove(int position) {
    // Verifica si la posición es válida antes de eliminar
    if (position >= 0 && position < list.size()) {
        list.erase(list.begin() + position); // Elimina el valor en la posición especificada
    }
}

// Método para renderizar la lista enlazada en una ventana SFML
void LinkedList::render(sf::RenderWindow& window) {
    // Carga la fuente para mostrar texto
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/DejaVuSans.ttf")) {
        cerr << "Failed to load font DejaVuSans.ttf" << endl;
        return;
    }

    float boxWidth = 80.0f;  // Ancho de cada nodo
    float boxHeight = 40.0f; // Altura de cada nodo

    // Recorre los elementos de la lista para dibujar cada nodo
    for (int i = 0; i < list.size(); ++i) {
        // Dibuja un rectángulo que representa un nodo
        sf::RectangleShape box(sf::Vector2f(boxWidth, boxHeight));
        box.setPosition(100 + i * (boxWidth + 10), window.getSize().y / 2 - boxHeight / 2);
        box.setFillColor(sf::Color::Yellow); // Color del nodo

        window.draw(box);

        // Dibuja el valor dentro del nodo
        sf::Text valueText;
        valueText.setFont(font);
        valueText.setString(to_string(list[i])); // Convierte el valor del nodo a texto
        valueText.setCharacterSize(20);
        valueText.setFillColor(sf::Color::Black); // Color del texto
        valueText.setPosition(box.getPosition().x + boxWidth / 4, box.getPosition().y + 5);
        window.draw(valueText);

        // Dibuja una flecha para conectar los nodos, excepto el último
        if (i < list.size() - 1) {
            sf::RectangleShape arrow(sf::Vector2f(30, 5)); // Flecha horizontal
            arrow.setPosition(100 + i * (boxWidth + 10) + boxWidth, window.getSize().y / 2 - 2);
            arrow.setFillColor(sf::Color::Black);
            window.draw(arrow);
        }
    }
}
