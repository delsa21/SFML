#ifndef STACKS_H
#define STACKS_H

#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

class Stack {
public:
    Stack();
    void push(int value);
    void pop();
    void render(sf::RenderWindow& window);

private:
    vector<int> stack;
    int maxSize;
};

#endif
