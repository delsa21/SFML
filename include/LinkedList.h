#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

// Clase que representa una lista enlazada (Linked List)
class LinkedList {
public:
    LinkedList(); // Constructor que inicializa una lista vacía

    // Inserta un valor en una posición específica de la lista
    void insert(int position, int value);

    // Elimina un elemento en una posición específica de la lista
    void remove(int position);

    // Renderiza visualmente la lista en una ventana SFML
    void render(sf::RenderWindow& window);

private:
    vector<int> list; // Vector que simula la lista enlazada para simplificar la implementación
};

#endif
