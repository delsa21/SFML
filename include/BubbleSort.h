#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

// Clase que representa el algoritmo de Bubble Sort (Ordenamiento Burbuja)
class BubbleSort {
public:
    // Constructor que inicializa el array con los datos proporcionados
    BubbleSort(const vector<int>& data);

    // Ejecuta el algoritmo de Bubble Sort para ordenar el array
    void sort();

    // Renderiza la visualización del proceso de ordenamiento en una ventana SFML
    void render(sf::RenderWindow& window);

private:
    vector<int> array; // Vector que contiene los datos a ordenar
    int currentIndex; // Índice del elemento actualmente comparado en el proceso
    bool sorted; // Indica si el array ya está completamente ordenado
};

#endif
