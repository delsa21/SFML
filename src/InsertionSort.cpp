#include "InsertionSort.h"
#include <iostream>

using namespace std;

// Constructor que inicializa el array y los índices para el algoritmo
InsertionSort::InsertionSort(const std::vector<int>& data) 
    : array(data), currentIndex(1), keyIndex(0), sorted(false) {}

// Método que ejecuta una iteración del algoritmo de ordenamiento por inserción
void InsertionSort::sort() {
    // Si ya se procesaron todos los elementos, marca como ordenado
    if (currentIndex >= array.size()) {
        sorted = true;
        return;
    }

    int key = array[currentIndex]; // Elemento actual a insertar en el subarray ordenado
    keyIndex = currentIndex - 1;

    // Desplaza elementos mayores hacia la derecha
    while (keyIndex >= 0 && array[keyIndex] > key) {
        array[keyIndex + 1] = array[keyIndex];
        --keyIndex;
    }

    // Inserta el elemento en la posición correcta
    array[keyIndex + 1] = key;

    // Avanza al siguiente elemento
    ++currentIndex;
}

// Método para renderizar el estado actual del array en una ventana SFML
void InsertionSort::render(sf::RenderWindow& window) {
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
        if (i == currentIndex) bar.setFillColor(sf::Color::Red);        // Elemento actual a insertar
        else if (i == keyIndex + 1) bar.setFillColor(sf::Color::Blue); // Posición donde se inserta el elemento
        else bar.setFillColor(sf::Color::White);                      // Elementos normales

        window.draw(bar); // Dibuja la barra en la ventana
    }
}
