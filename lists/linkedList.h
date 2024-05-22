#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <chrono>
#include <fstream>

using std::cout;
using std::endl;

// Node structure
template<typename T>
struct Node
{
    T Payload;
    Node* ptrNext;
    Node* ptrPrev;
};

// Prototypes for linkedList.cpp
template<typename T>
Node<T>* createNode(T);

template<typename T>
void insertFront(Node<T>**, T);

template<typename T>
void insertEnd(Node<T>**, T);

template<typename T>
void displayList(Node<T>*);

template<typename T>
void displayHeadAndTail(Node<T>*);

template<typename T>
void generateRandomList(Node<T>**, int);

template<typename T>
void cloneList(Node<T>*, Node<T>**);

template<typename T>
void swap(Node<T>*, Node<T>*);

template<typename T>
void readListFromFile(std::ifstream&, Node<T>**, int);

template<typename T>
void computeTimeAux(Node<T>*, int, void (*sortFunc)(Node<T>*, int), std::ofstream&);

template<typename T>
void computeTime(void (*sortFunc)(Node<T>*, int), std::ifstream&, std::ofstream&, const int, const int);

#endif // LINKEDLIST_H
