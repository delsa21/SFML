#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

// Clase que representa el algoritmo de ordenamiento rápido (Quick Sort)
class QuickSort {
public:
    // Constructor que inicializa el array con los datos proporcionados
    QuickSort(const vector<int>& data);

    // Ejecuta el algoritmo Quick Sort para ordenar el array
    void sort();

    // Renderiza la visualización del proceso de ordenamiento en una ventana SFML
    void render(sf::RenderWindow& window);

private:
    vector<int> array; // Vector que contiene los datos a ordenar
    bool sorted;       // Indica si el array ya está completamente ordenado

    // Método privado que implementa el algoritmo Quick Sort de forma recursiva
    void quickSort(int low, int high);

    // Realiza la partición del array y devuelve el índice del pivote
    int partition(int low, int high);

    // Renderiza el estado actual del array durante la partición
    void renderState(sf::RenderWindow& window, int low, int high, int pivotIndex);
};

#endif
