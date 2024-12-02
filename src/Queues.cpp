#include "Queues.h"
#include <iostream>

using namespace std;

// Constructor que inicializa la cola con un tamaño máximo predeterminado
Queue::Queue() : maxSize(10) {}

// Método para agregar un elemento al final de la cola
void Queue::enqueue(int value) {
    if (queue.size() < maxSize) { // Verifica si la cola no ha alcanzado su capacidad máxima
        queue.push_back(value);  // Agrega el valor al final de la cola
    }
}

// Método para eliminar un elemento del frente de la cola
void Queue::dequeue() {
    if (!queue.empty()) { // Verifica si la cola no está vacía
        queue.pop_front(); // Elimina el primer elemento de la cola
    }
}

// Método para renderizar gráficamente el estado actual de la cola en una ventana SFML
void Queue::render(sf::RenderWindow& window) {
    // Carga la fuente para mostrar texto
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/DejaVuSans.ttf")) {
        cerr << "Failed to load font DejaVuSans.ttf" << endl;
        return;
    }

    float boxWidth = 60.0f;  // Ancho de cada elemento (rectángulo)
    float boxHeight = 40.0f; // Altura de cada elemento (rectángulo)

    // Itera sobre los elementos de la cola para dibujarlos
    for (int i = 0; i < queue.size(); ++i) {
        // Dibuja un rectángulo que representa un elemento de la cola
        sf::RectangleShape box(sf::Vector2f(boxWidth, boxHeight));
        box.setPosition(100 + i * (boxWidth + 5), window.getSize().y / 2 - boxHeight / 2);
        box.setFillColor(sf::Color::Green); // Color del elemento

        window.draw(box);

        // Dibuja el valor del elemento dentro del rectángulo
        sf::Text valueText;
        valueText.setFont(font);
        valueText.setString(to_string(queue[i])); // Convierte el valor a texto
        valueText.setCharacterSize(20);
        valueText.setFillColor(sf::Color::White); // Color del texto
        valueText.setPosition(box.getPosition().x + boxWidth / 4, box.getPosition().y + 5);
        window.draw(valueText);
    }
}
