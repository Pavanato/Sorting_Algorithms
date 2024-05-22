#include "sorting.h"

// Implementation of the Selection Sort algorithm
template <typename T>
void Sorting::selectionSort(Node<T>* head, int iListLen) 
{
    Node<T>* current = head; // Pointer to the current node
    Node<T>* temp = head; // Temporary pointer to assist in swaps

    // Outer loop to traverse the list
    for (int OuterLoop = 0; OuterLoop < iListLen; OuterLoop++)
    {
        temp = current; // Set the temporary node as the current node

        // Inner loop to find the smallest element in the unsorted part of the list
        for (int InnerLoop = 0; InnerLoop < iListLen - OuterLoop; InnerLoop++)
        {
            // Verifies if the value of the current node is greater than the value of the temporary node
            if (current->Payload > temp->Payload)
            {
                swap(current, temp);
            }
            temp = temp->ptrNext; // Move to the next temporary node
        }
        current = current->ptrNext; // Move to the next current node
    }
}

// Implementation of the optimized Selection Sort algorithm
template <typename T>
void Sorting::optimizedSelectionSort(Node<T>* head, int iListLen)
{
    Node<T>* current = head; // Pointer to the current node
    Node<T>* temp; // Temporary pointer to assist in swaps
    Node<T>* smallest; // Pointer to the smallest element found

    // Outer loop to traverse the list
    for (int OuterLoop = 0; OuterLoop < iListLen; OuterLoop++)
    {
        smallest = current; // Define the smallest element as the current node
        temp = current->ptrNext; // Set the temporary node as the next node

        // Inner loop to find the smallest element in the unsorted part of the list
        for (int InnerLoop = 0; InnerLoop < iListLen - OuterLoop - 1; InnerLoop++)
        {
            // Verifies if the value of the smallest node is greater than the value of the temporary node
            if (smallest->Payload > temp->Payload)
            {
                smallest = temp; // Set the smallest element as the temporary node
            }
            temp = temp->ptrNext; // Move to the next temporary node
        }

        // If the smallest element is different from the current node, swap them
        if (smallest->Payload < current->Payload)
        {
            swap(smallest, current);
        }
        
        current = current->ptrNext; // Move to the next current node
    }
}

// Explicit template instantiation for int
template void Sorting::selectionSort<int>(Node<int>* head, int iListLen);
template void Sorting::optimizedSelectionSort<int>(Node<int>* head, int iListLen);