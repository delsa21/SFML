#include "BinarySearch.h"

// Constructor que inicializa el array y los índices para la búsqueda binaria
BinarySearch::BinarySearch(const vector<int>& data) 
    : array(data), left(0), right(data.size() - 1), found(false), targetIndex(-1) {}

// Método que ejecuta el algoritmo de búsqueda binaria para encontrar el elemento objetivo
void BinarySearch::search(int target) {
    while (left <= right) {
        mid = (left + right) / 2; // Calcula el índice del elemento medio
        if (array[mid] == target) { // Si se encuentra el objetivo
            targetIndex = mid;     // Guarda el índice del elemento encontrado
            found = true;          // Marca como encontrado
            break;
        } else if (array[mid] < target) { // Si el elemento medio es menor que el objetivo
            left = mid + 1; // Ajusta el límite izquierdo para buscar en la mitad derecha
        } else { // Si el elemento medio es mayor que el objetivo
            right = mid - 1; // Ajusta el límite derecho para buscar en la mitad izquierda
        }
    }
}

// Método para renderizar el array y la búsqueda en una ventana SFML
void BinarySearch::render(sf::RenderWindow& window) {
    float barWidth = window.getSize().x / array.size(); // Calcula el ancho de cada barra

    // Itera sobre el array para dibujar cada elemento como una barra
    for (int i = 0; i < array.size(); ++i) {
        sf::RectangleShape bar(sf::Vector2f(barWidth - 2, array[i] * 5)); // Representa un elemento como una barra
        bar.setPosition(i * barWidth, window.getSize().y - array[i] * 5); // Posiciona la barra en el eje X e Y

        // Cambia el color según el estado del elemento
        if (i == mid) bar.setFillColor(sf::Color::Red);        // Elemento actualmente en el medio
        else if (i == targetIndex) bar.setFillColor(sf::Color::Green); // Elemento objetivo encontrado
        else bar.setFillColor(sf::Color::White);              // Elementos normales

        window.draw(bar); // Dibuja la barra en la ventana
    }
}
