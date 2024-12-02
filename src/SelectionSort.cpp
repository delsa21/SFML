#include "SelectionSort.h"
#include <iostream>
using namespace std;

// Constructor que inicializa el array, índices y el estado de ordenamiento
SelectionSort::SelectionSort(const std::vector<int>& data) 
    : array(data), currentIndex(0), minIndex(0), sorted(false) {}

// Método principal que ejecuta una iteración del algoritmo de Selection Sort
void SelectionSort::sort() {
    // Verifica si el array ya está completamente ordenado
    if (currentIndex >= array.size() - 1) {
        sorted = true;
        return;
    }

    // Encuentra el índice del elemento mínimo en el subarray no ordenado
    minIndex = currentIndex;
    for (int j = currentIndex + 1; j < array.size(); ++j) {
        if (array[j] < array[minIndex]) {
            minIndex = j;
        }
    }

    // Intercambia el elemento actual con el elemento mínimo encontrado
    std::swap(array[currentIndex], array[minIndex]);

    // Avanza al siguiente elemento
    ++currentIndex;
}

// Método para renderizar gráficamente el estado actual del array en una ventana SFML
void SelectionSort::render(sf::RenderWindow& window) {
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
            bar.setFillColor(sf::Color::Red);  // Elemento actualmente seleccionado
        else if (i == minIndex) 
            bar.setFillColor(sf::Color::Blue); // Elemento mínimo encontrado
        else 
            bar.setFillColor(sf::Color::White); // Elementos normales

        window.draw(bar); // Dibuja la barra en la ventana
    }
}
