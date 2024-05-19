#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <chrono>
#include <fstream>

using std::cout;
using std::endl;

// Node structure
typedef struct Node
{
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

// Prototypes for linkedList.cpp
Node* createNode(int);
void insertFront(Node**, int);
void insertEnd(Node**, int);
void displayList(Node*);
void displayHeadAndTail(Node*);
void generateRandomList(Node**, int);
void cloneList(Node*, Node**);
void swap(Node*, Node*);
void readListFromFile(std::ifstream&, Node**, int);
void computeTimeAux(Node*, int, void (*sortFunc)(Node*, int), std::ofstream&);
void computeTime(void (*sortFunc)(Node*, int), std::ifstream& ,std::ofstream&, const int, const int);


#endif // LINKEDLIST_H