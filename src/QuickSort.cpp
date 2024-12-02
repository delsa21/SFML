#include "QuickSort.h"
#include <iostream>

// Constructor que inicializa el array y establece el estado de ordenamiento como no completado
QuickSort::QuickSort(const vector<int>& data) : array(data), sorted(false) {}

// Método principal que inicia el proceso de ordenamiento si aún no está ordenado
void QuickSort::sort() {
    if (!sorted) { // Solo realiza el ordenamiento si no se ha completado
        quickSort(0, array.size() - 1); // Llama al método recursivo quickSort
        sorted = true; // Marca el array como ordenado
    }
}

// Método recursivo para realizar el ordenamiento QuickSort
void QuickSort::quickSort(int low, int high) {
    if (low < high) { // Condición base: subarray con al menos dos elementos
        int pivotIndex = partition(low, high); // Encuentra la posición del pivote
        quickSort(low, pivotIndex - 1);        // Ordena los elementos menores al pivote
        quickSort(pivotIndex + 1, high);       // Ordena los elementos mayores al pivote
    }
}

// Método para realizar la partición del array
int QuickSort::partition(int low, int high) {
    int pivot = array[high]; // Elige el último elemento como pivote
    int i = low - 1;         // Índice para el menor elemento

    // Recorre el array para colocar los elementos menores al pivote a la izquierda
    for (int j = low; j < high; ++j) {
        if (array[j] <= pivot) { // Si el elemento es menor o igual al pivote
            ++i;
            swap(array[i], array[j]); // Intercambia el elemento con el mayor encontrado
        }
    }
    swap(array[i + 1], array[high]); // Coloca el pivote en su posición correcta
    return i + 1; // Devuelve la posición del pivote
}

// Método para renderizar gráficamente el estado actual del array en una ventana SFML
void QuickSort::render(sf::RenderWindow& window) {
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

        bar.setFillColor(sf::Color::White); // Color de las barras
        window.draw(bar); // Dibuja la barra en la ventana
    }

    window.display(); // Actualiza la ventana
}
