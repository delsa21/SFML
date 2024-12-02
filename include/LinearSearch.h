#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

// Clase que representa el algoritmo de búsqueda lineal (Linear Search)
class LinearSearch {
public:
    // Constructor que inicializa el array con los datos proporcionados
    LinearSearch(const vector<int>& data);

    // Busca un elemento objetivo (target) en el array
    void search(int target);

    // Renderiza la visualización del proceso de búsqueda en una ventana SFML
    void render(sf::RenderWindow& window);

private:
    vector<int> array; // Vector que contiene los datos a buscar
    int targetIndex;   // Índice donde se encuentra el elemento objetivo (si existe)
    int currentIndex;  // Índice del elemento actualmente en proceso de comparación
    bool found;        // Indica si el elemento objetivo fue encontrado
};

#endif
