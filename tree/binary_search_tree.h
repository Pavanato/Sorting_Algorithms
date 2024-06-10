#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

using namespace std;
#include <chrono>
#include <fstream>
#include "../lists/linkedlist.h"

namespace BinaryTree
{
    template<typename T>
    struct Node
    {
        T Payload;
        Node* ptrLeft;
        Node* ptrRight;
    };

    // Prototypes
    template<typename T>
    Node<T>* createTreeNode(T);

    template<typename T>
    Node<T>* insertTreeNode(Node<T>*, T);

    template<typename T>
    Node<T>* bfsSearch(Node<T>*, T);

    template<typename T>
    Node<T>* dfsSearch(Node<T>*, T);

    template<typename T>
    Node<T>* lesserLeaf(Node<T>*);

    template<typename T>
    int treeHeight(Node<T>*);

}


#include <iostream>






#endif // BINARY_SEARCH_TREE_H