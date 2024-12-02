#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

// Clase que representa el algoritmo de Búsqueda Binaria
class BinarySearch {
public:
    // Constructor que inicializa el array con los datos proporcionados
    BinarySearch(const vector<int>& data);

    // Busca un elemento objetivo (target) en el array utilizando búsqueda binaria
    void search(int target);

    // Renderiza la visualización del proceso de búsqueda en una ventana SFML
    void render(sf::RenderWindow& window);

private:
    vector<int> array; // Vector que contiene los datos ordenados para la búsqueda
    int left, right, mid; // Punteros que representan los límites y el elemento medio en cada iteración
    int targetIndex; // Índice del elemento objetivo si se encuentra
    bool found; // Indica si el elemento objetivo fue encontrado
};

#endif
