#include "sorting.h"

// Implementation of the Bubble Sort algorithm
void Sorting::bubbleSort(Node* head, int iListLen) 
{
    Node* current = head; // Pointer to the current node

    // Outer loop to traverse the list
    for (int OuterLoop = 0; OuterLoop < iListLen - 1; OuterLoop++)
    {
        // Loop interno para comparar pares adjacentes e fazer as trocas necessárias
        for (int InnerLoop = 0; InnerLoop < iListLen - 1; InnerLoop++)
        {
            // Verifies if the value of the current node is greater than the next node in the list
            if (current->iPayload > current->ptrNext->iPayload)
            {
                swap(current, current->ptrNext);
            }
            current = current->ptrNext; // Move to the next node
        }
        current = head; // Reset the current position to the beginning of the list
    }
}

// Implementation of the optimized Bubble Sort algorithm
void Sorting::optimizedBubbleSort(Node* head, int iListLen) 
{
    Node* current = head; // Pointer to the current node
    bool bSwapped; // Flag to check if a swap occurred

    // Outer loop to traverse the list
    for (int OuterLoop = 0; OuterLoop < iListLen - 1; OuterLoop++)
    {
        bSwapped = false; // Reset the swap flag

        // Inner loop to compare adjacent pairs and make the necessary swaps
        for (int InnerLoop = 0; InnerLoop < iListLen - OuterLoop - 1; InnerLoop++)
        {
            // Verifies if the value of the current node is greater than the next node in the list
            if (current->iPayload > current->ptrNext->iPayload)
            {
                swap(current, current->ptrNext);
                bSwapped = true; // Set the swap flag to true
            }
            
            current = current->ptrNext; // Move to the next node
        }
        
        // If no swaps were made, the list is already sorted
        if (bSwapped == false)
        {
            break;
        }

        current = head; // Reset the current position to the beginning of the list
    }
}
