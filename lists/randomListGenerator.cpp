#include <iostream>
#include <random>
#include "linkedlist.h"

using std::cout;
using std::endl;

int main()
{
    const int listSize = 10000;
    const int numLists = 100;

    for (int i = 0; i < numLists; ++i) {
        Node<int>* head = nullptr;
        generateRandomList<int>(&head, listSize);
        displayList<int>(head);
    }

    return 0;
}
