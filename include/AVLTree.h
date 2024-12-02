#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
using namespace std;

class AVLNode {
public:
    int value;
    int height;
    shared_ptr<AVLNode> left, right;

    AVLNode(int val) : value(val), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
public:
    AVLTree();
    void insert(int value);
    void remove(int value);
    void render(sf::RenderWindow& window);

private:
    shared_ptr<AVLNode> root;

    shared_ptr<AVLNode> insert(shared_ptr<AVLNode> node, int value);
    shared_ptr<AVLNode> remove(shared_ptr<AVLNode> node, int value);
    shared_ptr<AVLNode> rotateLeft(shared_ptr<AVLNode> node);
    shared_ptr<AVLNode> rotateRight(shared_ptr<AVLNode> node);
    int getHeight(shared_ptr<AVLNode> node);
    int getBalanceFactor(shared_ptr<AVLNode> node);
    void renderNode(shared_ptr<AVLNode> node, sf::RenderWindow& window, float x, float y, float xOffset);
};

#endif
