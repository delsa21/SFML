#ifndef STACK_H
#define STACK_H

#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

// Clase que representa una pila (Stack)
class Stack {
public:
    Stack(); // Constructor que inicializa la pila como vacía

    // Agrega un elemento en la parte superior de la pila
    void push(int value);

    // Elimina el elemento en la parte superior de la pila
    void pop();

    // Devuelve el elemento en la parte superior de la pila sin eliminarlo
    int top() const;

    // Verifica si la pila está vacía
    bool isEmpty() const;

    // Renderiza la pila visualmente en una ventana SFML
    void render(sf::RenderWindow& window);

private:
    vector<int> data; // Contenedor que almacena los elementos de la pila
};

#endif // STACK_H
