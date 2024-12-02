#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

class LinkedList {
public:
    LinkedList();
    void insert(int position, int value);
    void remove(int position);
    void render(sf::RenderWindow& window);

private:
    vector<int> list;
};

#endif
