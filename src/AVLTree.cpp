#include "AVLTree.h"

// Constructor que inicializa el árbol AVL con una raíz nula
AVLTree::AVLTree() : root(nullptr) {}

// Obtiene la altura de un nodo. Si es nulo, retorna 0.
int AVLTree::getHeight(shared_ptr<AVLNode> node) {
    return node ? node->height : 0;
}

// Calcula el factor de balanceo de un nodo
int AVLTree::getBalanceFactor(shared_ptr<AVLNode> node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Realiza una rotación hacia la izquierda para balancear el árbol
shared_ptr<AVLNode> AVLTree::rotateLeft(shared_ptr<AVLNode> node) {
    shared_ptr<AVLNode> rightChild = node->right;
    node->right = rightChild->left;
    rightChild->left = node;

    // Actualiza las alturas de los nodos afectados
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    rightChild->height = max(getHeight(rightChild->left), getHeight(rightChild->right)) + 1;

    return rightChild;
}

// Realiza una rotación hacia la derecha para balancear el árbol
shared_ptr<AVLNode> AVLTree::rotateRight(shared_ptr<AVLNode> node) {
    shared_ptr<AVLNode> leftChild = node->left;
    node->left = leftChild->right;
    leftChild->right = node;

    // Actualiza las alturas de los nodos afectados
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    leftChild->height = max(getHeight(leftChild->left), getHeight(leftChild->right)) + 1;

    return leftChild;
}

// Inserta un valor en el árbol de manera recursiva
shared_ptr<AVLNode> AVLTree::insert(shared_ptr<AVLNode> node, int value) {
    // Inserta un nuevo nodo si el nodo actual es nulo
    if (!node) return make_shared<AVLNode>(value);

    // Inserción recursiva
    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);
    else
        return node; // Valor duplicado, no se inserta

    // Actualiza la altura del nodo
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    // Calcula el factor de balanceo y realiza las rotaciones necesarias
    int balanceFactor = getBalanceFactor(node);

    // Casos de desbalance
    if (balanceFactor > 1 && value < node->left->value) return rotateRight(node); // Rotación derecha
    if (balanceFactor < -1 && value > node->right->value) return rotateLeft(node); // Rotación izquierda
    if (balanceFactor > 1 && value > node->left->value) { // Rotación izquierda-derecha
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balanceFactor < -1 && value < node->right->value) { // Rotación derecha-izquierda
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Inserta un valor en el árbol AVL
void AVLTree::insert(int value) {
    root = insert(root, value);
}

// Renderiza un nodo y sus conexiones en la ventana SFML
void AVLTree::renderNode(shared_ptr<AVLNode> node, sf::RenderWindow& window, float x, float y, float xOffset) {
    if (!node) return;

    // Carga una fuente para mostrar los valores de los nodos
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/DejaVuSans.ttf")) {
        cerr << "Failed to load font DejaVuSans.ttf" << endl;
        return;
    }

    // Dibuja el nodo como un círculo verde
    sf::CircleShape circle(20);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(x, y);
    window.draw(circle);

    // Muestra el valor del nodo dentro del círculo
    sf::Text text;
    text.setFont(font);
    text.setString(to_string(node->value));
    text.setCharacterSize(15);
    text.setFillColor(sf::Color::Black);
    text.setPosition(x + 10, y + 5);
    window.draw(text);

    // Renderiza la conexión y los nodos hijos
    if (node->left) {
        sf::Vertex line[] = {sf::Vertex(sf::Vector2f(x + 20, y + 20)), sf::Vertex(sf::Vector2f(x - xOffset + 20, y + 80))};
        window.draw(line, 2, sf::Lines);
        renderNode(node->left, window, x - xOffset, y + 80, xOffset / 2);
    }
    if (node->right) {
        sf::Vertex line[] = {sf::Vertex(sf::Vector2f(x + 20, y + 20)), sf::Vertex(sf::Vector2f(x + xOffset + 20, y + 80))};
        window.draw(line, 2, sf::Lines);
        renderNode(node->right, window, x + xOffset, y + 80, xOffset / 2);
    }
}

// Renderiza todo el árbol AVL en la ventana SFML
void AVLTree::render(sf::RenderWindow& window) {
    renderNode(root, window, window.getSize().x / 2, 50, 200); // Llama a la renderización recursiva desde la raíz
}
