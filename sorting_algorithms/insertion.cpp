#include "sorting.h"

// Implementation of the Insertion Sort algorithm
template <typename T>
void Sorting::insertionSort(Node<T>* head, int iListLen)
{
    Node<T>* insert = head; // Pointer to the node to be inserted
    Node<T>* inner = head->ptrNext; // Pointer to the node to be compared
    // Outer loop to traverse the list
    for (int iOuterLoop = 0; iOuterLoop < iListLen - 1; iOuterLoop++)
    {
        // Traverse the list until the end (ptrNext of the last node is NULL)
        while (inner->ptrPrev != nullptr && inner->Payload < inner->ptrPrev->Payload)
        {
            swap(inner, inner->ptrPrev);
            inner = inner->ptrPrev; // Move to the previous node
        }
        insert = insert->ptrNext; // Move to the next node
        inner = insert->ptrNext; // Move to the next node to be compared
    }
}

// Explicit template instantiation for int
template void Sorting::insertionSort<int>(Node<int>* head, int iListLen);