#ifndef STACK_H
#define STACK_H

#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

class Stack {
public:
    Stack();

    // Operaciones básicas
    void push(int value);
    void pop();
    int top() const;
    bool isEmpty() const;

    // Renderizar la pila
    void render(sf::RenderWindow& window);

private:
    vector<int> data;
};

#endif // STACK_H
