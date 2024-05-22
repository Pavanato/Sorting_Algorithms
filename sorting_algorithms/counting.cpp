#include "sorting.h"

template<typename T>
void Sorting::countingSort(Node<T>* head, int iListLen) 
{
    // Find minimum and maximum values in the list
    T minValue = head->Payload;
    T maxValue = head->Payload;
    Node<T>* current = head->ptrNext;
    while (current != nullptr) {
        if (current->Payload < minValue)
            minValue = current->Payload;
        else if (current->Payload > maxValue)
            maxValue = current->Payload;
        current = current->ptrNext;
    }

    // Determine the range of values
    int range = maxValue - minValue + 1;

    // Create an array to store the count of each element
    int* countArray[range] = {0};
    
    // Count the occurrences of each element
    current = head;
    while (current != nullptr) {
        countArray[current->Payload - minValue]++;
        current = current->ptrNext;
    }

    // Update the original list with sorted elements
    current = head;
    int index = 0;
    while (current != nullptr) {
        while (countArray[index] == 0)
            index++; // Skip elements with count 0
        current->Payload = index + minValue;
        countArray[index]--;
        current = current->ptrNext;
    }
}

// Explicit template instantiation for int
template void Sorting::countingSort<int>(Node<int>*, int);
