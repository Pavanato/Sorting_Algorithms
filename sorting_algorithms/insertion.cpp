#include "sorting.h"

// Implementation of the Insertion Sort algorithm
void Sorting::insertionSort(Node* head, int iListLen)
{
    Node* insert = head; // Pointer to the node to be inserted
    Node* inner = head->ptrNext; // Pointer to the node to be compared
    // Outer loop to traverse the list
    for (int iOuterLoop = 0; iOuterLoop < iListLen - 1; iOuterLoop++)
    {
        // Traverse the list until the end (ptrNext of the last node is NULL)
        while (inner->ptrPrev != nullptr && inner->iPayload < inner->ptrPrev->iPayload)
        {
            swap(inner, inner->ptrPrev);
            inner = inner->ptrPrev; // Move to the previous node
        }
        insert = insert->ptrNext; // Move to the next node
        inner = insert->ptrNext; // Move to the next node to be compared
    }
}