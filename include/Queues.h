#ifndef QUEUES_H
#define QUEUES_H

#include <SFML/Graphics.hpp>
#include <deque>
using namespace std;

class Queue {
public:
    Queue();
    void enqueue(int value);
    void dequeue();
    void render(sf::RenderWindow& window);

private:
    deque<int> queue;
    int maxSize;
};

#endif
