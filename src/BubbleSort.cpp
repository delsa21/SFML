#include "BubbleSort.h"
#include <iostream>

// Constructor que inicializa el array y los índices necesarios para el algoritmo
BubbleSort::BubbleSort(const vector<int>& data) : array(data), currentIndex(0), sorted(false) {}

// Método que ejecuta una iteración del algoritmo de ordenamiento por burbuja
void BubbleSort::sort() {
    if (sorted) return; // Si ya está ordenado, no realiza más operaciones

    bool swapped = false; // Indica si se realizaron intercambios en esta iteración

    // Recorre el array hasta la posición no ordenada actual
    for (int i = 0; i < array.size() - 1 - currentIndex; ++i) {
        // Compara elementos adyacentes
        if (array[i] > array[i + 1]) {
            swap(array[i], array[i + 1]); // Intercambia si están en el orden incorrecto
            swapped = true; // Marca que hubo un intercambio
        }
    }

    // Si no hubo intercambios, el array ya está ordenado
    if (!swapped) sorted = true;

    ++currentIndex; // Incrementa el índice para no procesar elementos ya ordenados
}

// Método para renderizar el estado actual del array en una ventana SFML
void BubbleSort::render(sf::RenderWindow& window) {
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
        if (i == currentIndex || i == currentIndex - 1) 
            bar.setFillColor(sf::Color::Red); // Elementos actualmente comparados
        else 
            bar.setFillColor(sf::Color::White); // Elementos normales

        window.draw(bar); // Dibuja la barra en la ventana
    }
}
