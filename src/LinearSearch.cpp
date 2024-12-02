#include "LinearSearch.h"
#include <iostream>

using namespace std;

// Constructor que inicializa el array y los índices necesarios para la búsqueda
LinearSearch::LinearSearch(const vector<int>& data) 
    : array(data), currentIndex(0), found(false), targetIndex(-1) {}

// Método que realiza la búsqueda lineal
void LinearSearch::search(int target) {
    for (currentIndex = 0; currentIndex < array.size(); ++currentIndex) {
        // Si se encuentra el elemento objetivo, guarda su índice y termina la búsqueda
        if (array[currentIndex] == target) {
            targetIndex = currentIndex;
            found = true;
            break;
        }
    }
}

// Método para renderizar el estado actual del array y la búsqueda en una ventana SFML
void LinearSearch::render(sf::RenderWindow& window) {
    // Carga la fuente para mostrar texto
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/DejaVuSans.ttf")) {
        cerr << "Failed to load font DejaVuSans.ttf" << endl;
        return;
    }

    float barWidth = window.getSize().x / array.size(); // Calcula el ancho de cada barra

    // Itera sobre el array para dibujar cada elemento como una barra
    for (int i = 0; i < array.size(); ++i) {
        sf::RectangleShape bar(sf::Vector2f(barWidth - 2, array[i] * 5)); // Representa un elemento como una barra
        bar.setPosition(i * barWidth, window.getSize().y - array[i] * 5); // Posiciona la barra en el eje X e Y

        // Cambia el color según el estado del elemento
        if (i == currentIndex) 
            bar.setFillColor(sf::Color::Red); // Elemento actualmente comparado
        else if (i == targetIndex) 
            bar.setFillColor(sf::Color::Green); // Elemento objetivo encontrado
        else 
            bar.setFillColor(sf::Color::White); // Elementos normales

        window.draw(bar); // Dibuja la barra en la ventana
    }
}
