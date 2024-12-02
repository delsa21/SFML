#include "Stack.h"
#include <iostream>

// Constructor que inicializa la pila
Stack::Stack() {}

// Método para insertar un elemento en la pila
void Stack::push(int value) {
    data.push_back(value); // Agrega el elemento al final del vector
}

// Método para eliminar el elemento superior de la pila
void Stack::pop() {
    if (!data.empty()) { // Verifica si la pila no está vacía
        data.pop_back(); // Elimina el último elemento del vector
    } else {
        std::cerr << "Stack is empty, cannot pop." << std::endl; // Muestra un mensaje de error si la pila está vacía
    }
}

// Método para obtener el elemento superior de la pila sin eliminarlo
int Stack::top() const {
    if (!data.empty()) { // Verifica si la pila no está vacía
        return data.back(); // Devuelve el último elemento del vector
    } else {
        std::cerr << "Stack is empty, cannot top." << std::endl; // Muestra un mensaje de error si la pila está vacía
        return -1; // Devuelve un valor de error
    }
}

// Método para verificar si la pila está vacía
bool Stack::isEmpty() const {
    return data.empty(); // Devuelve true si el vector está vacío
}

// Método para renderizar gráficamente la pila en una ventana SFML
void Stack::render(sf::RenderWindow& window) {
    window.clear(sf::Color::White); // Limpia la ventana con color blanco

    sf::Font font;
    if (!font.loadFromFile("assets/fonts/DejaVuSans.ttf")) { // Carga la fuente para mostrar texto
        std::cerr << "Failed to load font DejaVuSans.ttf" << std::endl;
        return;
    }

    // Recorre los elementos de la pila y los dibuja como texto en la ventana
    for (int i = 0; i < data.size(); i++) {
        sf::Text text(std::to_string(data[i]), font, 24); // Convierte el elemento a texto
        text.setPosition(50, 50 + i * 30); // Posiciona cada elemento en la ventana
        text.setFillColor(sf::Color::Black); // Color del texto
        window.draw(text); // Dibuja el texto en la ventana
    }

    window.display(); // Muestra los cambios en la ventana
}
