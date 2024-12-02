#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

// Clase que representa el algoritmo de ordenamiento por mezcla (Merge Sort)
class MergeSort {
public:
    // Constructor que inicializa el array con los datos proporcionados
    MergeSort(const std::vector<int>& data);

    // Ejecuta el algoritmo de Merge Sort para ordenar el array
    void sort();

    // Renderiza la visualización del proceso de ordenamiento en una ventana SFML
    void render(sf::RenderWindow& window);

private:
    // Método recursivo que divide el array en subarreglos más pequeños
    void mergeSort(int left, int right);

    // Mezcla dos subarreglos ordenados en un único subarreglo ordenado
    void merge(int left, int mid, int right);

    vector<int> array;       // Vector que contiene los datos a ordenar
    vector<int> tempArray;   // Vector temporal para realizar la mezcla de subarreglos
    bool sorted;             // Indica si el array ya está completamente ordenado
    int currentLeft;         // Índice izquierdo del subarreglo actual
    int currentRight;        // Índice derecho del subarreglo actual
    int midPoint;            // Punto medio del subarreglo actual
};

#endif
