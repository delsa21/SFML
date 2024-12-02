#include "MergeSort.h"
#include <iostream>

using namespace std;

// Constructor que inicializa el array, el array temporal y otros indicadores
MergeSort::MergeSort(const std::vector<int>& data) 
    : array(data), tempArray(data.size()), sorted(false), currentLeft(0), currentRight(data.size() - 1), midPoint(0) {}

// Método que ejecuta el algoritmo de Merge Sort
void MergeSort::sort() {
    if (!sorted) { // Si el array no está ordenado, inicia el proceso
        mergeSort(0, array.size() - 1);
        sorted = true; // Marca como ordenado al completar
    }
}

// Método recursivo para dividir el array en subarrays más pequeños
void MergeSort::mergeSort(int left, int right) {
    if (left >= right) return; // Caso base: subarray de un solo elemento

    int mid = left + (right - left) / 2; // Calcula el punto medio
    mergeSort(left, mid);                // Divide la primera mitad
    mergeSort(mid + 1, right);           // Divide la segunda mitad
    merge(left, mid, right);             // Combina las mitades ordenadas
}

// Método para combinar dos subarrays ordenados
void MergeSort::merge(int left, int mid, int right) {
    int i = left;       // Índice para el primer subarray
    int j = mid + 1;    // Índice para el segundo subarray
    int k = left;       // Índice para el array temporal

    // Combina los elementos de ambos subarrays en orden
    while (i <= mid && j <= right) {
        if (array[i] <= array[j]) {
            tempArray[k++] = array[i++];
        } else {
            tempArray[k++] = array[j++];
        }
    }

    // Copia los elementos restantes del primer subarray (si los hay)
    while (i <= mid) tempArray[k++] = array[i++];

    // Copia los elementos restantes del segundo subarray (si los hay)
    while (j <= right) tempArray[k++] = array[j++];

    // Copia los elementos ordenados del array temporal al array original
    for (int idx = left; idx <= right; ++idx) {
        array[idx] = tempArray[idx];
    }

    // Actualiza los indicadores para la visualización
    currentLeft = left;
    midPoint = mid;
    currentRight = right;
}

// Método para renderizar el estado actual del array en una ventana SFML
void MergeSort::render(sf::RenderWindow& window) {
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
        if (i >= currentLeft && i <= currentRight) 
            bar.setFillColor(sf::Color::Blue); // Elementos actualmente procesados
        else 
            bar.setFillColor(sf::Color::White); // Elementos normales

        window.draw(bar); // Dibuja la barra en la ventana
    }
}
