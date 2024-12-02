#include <SFML/Graphics.hpp>
#include <iostream>
#include "LinearSearch.h"
#include "BinarySearch.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "AVLTree.h"
#include "Dijkstra.h"
#include "Queues.h"
#include "Stacks.h"
#include "LinkedList.h"

using namespace std;

// Función para mostrar el menú principal
void displayMenu(sf::RenderWindow& window, sf::Font& font) {
    window.clear(sf::Color::White);

    vector<string> menuItems = {
        "1. Sorting Algorithms",
        "2. Linear Data Structures",
        "3. Search Algorithms",
        "4. Non-Linear Data Structures",
        "5. Exit"
    };

    for (int i = 0; i < menuItems.size(); i++) {
        sf::Text text(menuItems[i], font, 64);
        text.setPosition(50, 50 + i * 60);
        text.setFillColor(sf::Color::Black);
        window.draw(text);
    }

    window.display();
}

// Función para mostrar submenús
void displaySubMenu(sf::RenderWindow& window, sf::Font& font, const string& category, const vector<string>& options) {
    window.clear(sf::Color(30, 30, 30));

    sf::Text title(category, font, 28);
    title.setPosition(50, 20);
    title.setFillColor(sf::Color::Yellow);
    window.draw(title);

    for (int i = 0; i < options.size(); i++) {
        sf::Text text(options[i], font, 24);
        text.setPosition(50, 80 + i * 50);
        text.setFillColor(sf::Color::Green);
        window.draw(text);
    }

    window.display();
}

// Función principal
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Algorithms and Data Structures Menu");

    sf::Font font;
    if (!font.loadFromFile("/Users/diana/C++/ACT15/assets/fonts/arial.ttf")) {
    cerr << "Failed to load font arial.ttf" << endl;
    return 1;
}



    bool inMainMenu = true;
    int selectedOption = -1;

    // Crear instancias de algoritmos y estructuras
    LinearSearch linearSearch({10, 20, 30, 40, 50});
    BinarySearch binarySearch({10, 20, 30, 40, 50});
    BubbleSort bubbleSort({5, 4, 3, 2, 1});
    SelectionSort selectionSort({5, 4, 3, 2, 1});
    InsertionSort insertionSort({5, 4, 3, 2, 1});
    MergeSort mergeSort({5, 4, 3, 2, 1});
    QuickSort quickSort({50, 30, 20, 10, 40});
    AVLTree avlTree;
    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(5);
    Dijkstra graph;
    graph.addEdge(1, 2, 4);
    graph.addEdge(1, 3, 2);
    graph.addEdge(2, 3, 1);
    Queue queue;
    Stack stack;
    LinkedList linkedList;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                if (inMainMenu) {
                    if (event.key.code == sf::Keyboard::Num1) {
                        selectedOption = 1;
                        inMainMenu = false;
                    } else if (event.key.code == sf::Keyboard::Num2) {
                        selectedOption = 2;
                        inMainMenu = false;
                    } else if (event.key.code == sf::Keyboard::Num3) {
                        selectedOption = 3;
                        inMainMenu = false;
                    } else if (event.key.code == sf::Keyboard::Num4) {
                        selectedOption = 4;
                        inMainMenu = false;
                    } else if (event.key.code == sf::Keyboard::Num5) {
                        window.close();
                    }
                } else {
                    if (event.key.code == sf::Keyboard::Escape) {
                        inMainMenu = true;
                        selectedOption = -1;
                    }
                }
            }
        }

        if (inMainMenu) {
            displayMenu(window, font);
        } else {
            if (selectedOption == 1) {
                displaySubMenu(window, font, "Sorting Algorithms", {"1. Bubble Sort", "2. Selection Sort", "3. Insertion Sort", "4. Merge Sort", "5. Quick Sort", "Press Esc to return"});
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Num1) {
                        bubbleSort.sort();
                        bubbleSort.render(window);
                    } else if (event.key.code == sf::Keyboard::Num2) {
                        selectionSort.sort();
                        selectionSort.render(window);
                    } else if (event.key.code == sf::Keyboard::Num3) {
                        insertionSort.sort();
                        insertionSort.render(window);
                    } else if (event.key.code == sf::Keyboard::Num4) {
                        mergeSort.sort();
                        mergeSort.render(window);
                    } else if (event.key.code == sf::Keyboard::Num5) {
                        quickSort.sort();
                        quickSort.render(window);
                    }
                }
            } else if (selectedOption == 2) {
                displaySubMenu(window, font, "Linear Data Structures", {"1. Stack", "2. Queue", "3. Linked List", "Press Esc to return"});
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Num1) {
                        stack.push(10);
                        stack.render(window);
                    } else if (event.key.code == sf::Keyboard::Num2) {
                        queue.enqueue(20);
                        queue.render(window);
                    } else if (event.key.code == sf::Keyboard::Num3) {
                        linkedList.insert(0, 30);
                        linkedList.render(window);
                    }
                }
            } else if (selectedOption == 3) {
                displaySubMenu(window, font, "Search Algorithms", {"1. Linear Search", "2. Binary Search", "Press Esc to return"});
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Num1) {
                        linearSearch.search(30);
                        linearSearch.render(window);
                    } else if (event.key.code == sf::Keyboard::Num2) {
                        binarySearch.search(30);
                        binarySearch.render(window);
                    }
                }
            } else if (selectedOption == 4) {
                displaySubMenu(window, font, "Non-Linear Data Structures", {"1. AVL Tree", "2. Dijkstra's Algorithm", "Press Esc to return"});
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Num1) {
                        avlTree.render(window);
                    } else if (event.key.code == sf::Keyboard::Num2) {
                        graph.findShortestPath(1, window);
                    }
                }
            }
        }
    }

    return 0;
}
