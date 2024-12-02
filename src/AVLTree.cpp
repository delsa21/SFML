#include "AVLTree.h"

AVLTree::AVLTree() : root(nullptr) {}

int AVLTree::getHeight(shared_ptr<AVLNode> node) {
    return node ? node->height : 0;
}

int AVLTree::getBalanceFactor(shared_ptr<AVLNode> node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

shared_ptr<AVLNode> AVLTree::rotateLeft(shared_ptr<AVLNode> node) {
    shared_ptr<AVLNode> rightChild = node->right;
    node->right = rightChild->left;
    rightChild->left = node;
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    rightChild->height = max(getHeight(rightChild->left), getHeight(rightChild->right)) + 1;
    return rightChild;
}

shared_ptr<AVLNode> AVLTree::rotateRight(shared_ptr<AVLNode> node) {
    shared_ptr<AVLNode> leftChild = node->left;
    node->left = leftChild->right;
    leftChild->right = node;
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    leftChild->height = max(getHeight(leftChild->left), getHeight(leftChild->right)) + 1;
    return leftChild;
}

shared_ptr<AVLNode> AVLTree::insert(shared_ptr<AVLNode> node, int value) {
    if (!node) return make_shared<AVLNode>(value);
    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);
    else
        return node;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    int balanceFactor = getBalanceFactor(node);

    // Balancing
    if (balanceFactor > 1 && value < node->left->value) return rotateRight(node);
    if (balanceFactor < -1 && value > node->right->value) return rotateLeft(node);
    if (balanceFactor > 1 && value > node->left->value) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balanceFactor < -1 && value < node->right->value) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void AVLTree::insert(int value) {
    root = insert(root, value);
}

void AVLTree::renderNode(shared_ptr<AVLNode> node, sf::RenderWindow& window, float x, float y, float xOffset) {
    if (!node) return;

    sf::CircleShape circle(20);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(x, y);
    window.draw(circle);

    sf::Text text;
    sf::Font font;
    font.loadFromFile("arial.ttf");
    text.setFont(font);
    text.setString(to_string(node->value));
    text.setCharacterSize(15);
    text.setFillColor(sf::Color::Black);
    text.setPosition(x + 10, y + 5);
    window.draw(text);

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

void AVLTree::render(sf::RenderWindow& window) {
    renderNode(root, window, window.getSize().x / 2, 50, 200);
}
