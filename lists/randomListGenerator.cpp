#include <iostream>
#include <random>
#include "linkedList.h"

using std::cout;
using std::endl;

// Not part of the linkedList.h file because it is run only once

int main()
{
    const int listSize = 10000;
    const int numLists = 100;

    for (int i = 0; i < numLists; ++i) {
        Node* head = nullptr;
        generateRandomList(&head, listSize);
        displayList(head);
    }
}