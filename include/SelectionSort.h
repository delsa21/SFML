#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

// Clase que representa el algoritmo de ordenamiento por selección (Selection Sort)
class SelectionSort {
public:
    // Constructor que inicializa el array con los datos proporcionados
    SelectionSort(const vector<int>& data);

    // Ejecuta el algoritmo Selection Sort para ordenar el array
    void sort();

    // Renderiza la visualización del proceso de ordenamiento en una ventana SFML
    void render(sf::RenderWindow& window);

private:
    vector<int> array; // Vector que contiene los datos a ordenar
    int currentIndex;       // Índice del elemento actualmente seleccionado
    int minIndex;           // Índice del elemento mínimo encontrado
    bool sorted;            // Indica si el array ya está completamente ordenado
};

#endif
