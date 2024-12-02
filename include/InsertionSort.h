#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

// Clase que representa el algoritmo de ordenamiento por inserción (Insertion Sort)
class InsertionSort {
public:
    // Constructor que inicializa el array con los datos proporcionados
    InsertionSort(const vector<int>& data);

    // Ejecuta el algoritmo de ordenamiento por inserción
    void sort();

    // Renderiza la visualización del proceso de ordenamiento en una ventana SFML
    void render(sf::RenderWindow& window);

private:
    vector<int> array; // Vector que contiene los datos a ordenar
    int currentIndex;  // Índice del elemento actualmente en proceso de inserción
    int keyIndex;      // Índice del elemento clave que se está comparando
    bool sorted;       // Indica si el array ya está completamente ordenado
};

#endif
