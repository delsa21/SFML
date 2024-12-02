#ifndef QUEUES_H
#define QUEUES_H

#include <SFML/Graphics.hpp>
#include <deque>
using namespace std;

// Clase que representa una cola (Queue) utilizando un deque para su implementación
class Queue {
public:
    Queue(); // Constructor que inicializa una cola vacía

    // Agrega un elemento al final de la cola
    void enqueue(int value);

    // Elimina un elemento del frente de la cola
    void dequeue();

    // Renderiza visualmente la cola en una ventana SFML
    void render(sf::RenderWindow& window);

private:
    deque<int> queue; // Deque utilizado para manejar la cola
    int maxSize;      // Tamaño máximo de la cola (opcional, para limitar el número de elementos)
};

#endif
