#include "sorting.h"

template<typename T>
void Sorting::bubbleSort(Node<T>* head, int iListLen) 
{
    if (head == nullptr) return;

    Node<T>* current = head;

    // Outer loop to traverse the list
    for (int OuterLoop = 0; OuterLoop < iListLen - 1; OuterLoop++)
    {
        current = head; // Reset current at the start of each outer loop
        for (int InnerLoop = 0; InnerLoop < iListLen - OuterLoop - 1; InnerLoop++)
        {
            // 
            if (current->ptrNext != nullptr && current->Payload > current->ptrNext->Payload)
            {
                swap(current, current->ptrNext);
            }
            current = current->ptrNext;
        }
    }
}

template<typename T>
void Sorting::optimizedBubbleSort(Node<T>* head, int iListLen) 
{
    if (head == nullptr) return;

    Node<T>* current = head;
    bool bSwapped; // Flag to check if any swaps were made

    // Outer loop to traverse the list
    for (int OuterLoop = 0; OuterLoop < iListLen - 1; OuterLoop++)
    {
        bSwapped = false;
        current = head; // Reset current at the start of each outer loop

        for (int InnerLoop = 0; InnerLoop < iListLen - OuterLoop - 1; InnerLoop++)
        {
            if (current->ptrNext != nullptr && current->Payload > current->ptrNext->Payload)
            {
                swap(current, current->ptrNext);
                bSwapped = true;
            }
            current = current->ptrNext;
        }

        // If no swaps were made, the list is sorted
        if (!bSwapped)
        {
            break;
        }
    }
}

// Explicit template instantiation for int
template void Sorting::bubbleSort<int>(Node<int>* head, int iListLen);
template void Sorting::optimizedBubbleSort<int>(Node<int>* head, int iListLen);
