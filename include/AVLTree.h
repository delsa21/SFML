#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
using namespace std;

// Clase que representa un nodo del árbol AVL
class AVLNode {
public:
    int value; // Valor almacenado en el nodo
    int height; // Altura del nodo
    shared_ptr<AVLNode> left, right; // Punteros a los hijos izquierdo y derecho

    // Constructor para inicializar un nodo con un valor
    AVLNode(int val) : value(val), height(1), left(nullptr), right(nullptr) {}
};

// Clase que representa un árbol AVL
class AVLTree {
public:
    AVLTree(); // Constructor para inicializar el árbol
    void insert(int value); // Inserta un valor en el árbol
    void remove(int value); // Elimina un valor del árbol
    void render(sf::RenderWindow& window); // Renderiza el árbol en una ventana SFML

private:
    shared_ptr<AVLNode> root; // Raíz del árbol AVL

    // Inserta un valor en el subárbol con raíz en 'node'
    shared_ptr<AVLNode> insert(shared_ptr<AVLNode> node, int value);

    // Elimina un valor del subárbol con raíz en 'node'
    shared_ptr<AVLNode> remove(shared_ptr<AVLNode> node, int value);

    // Rotación hacia la izquierda para balancear el árbol
    shared_ptr<AVLNode> rotateLeft(shared_ptr<AVLNode> node);

    // Rotación hacia la derecha para balancear el árbol
    shared_ptr<AVLNode> rotateRight(shared_ptr<AVLNode> node);

    // Obtiene la altura de un nodo
    int getHeight(shared_ptr<AVLNode> node);

    // Calcula el factor de balanceo de un nodo
    int getBalanceFactor(shared_ptr<AVLNode> node);

    // Renderiza recursivamente un nodo y sus hijos
    void renderNode(shared_ptr<AVLNode> node, sf::RenderWindow& window, float x, float y, float xOffset);
};

#endif
