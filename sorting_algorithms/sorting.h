#ifndef SORTING_H
#define SORTING_H

#include "../lists/linkedList.h"

// Namespace for the sorting algorithms
namespace Sorting {
    void bubbleSort(Node*, int);
    void optimizedBubbleSort(Node*, int);
    void insertionSort(Node*, int);
    void selectionSort(Node*, int);
    void optimizedSelectionSort(Node*, int);
}

#endif // SORTING_H