#ifndef SORTING_H
#define SORTING_H

#include "../lists/linkedlist.h"

using namespace LinkedList;

// Namespace for the sorting algorithms
namespace Sorting {
    template<typename T>
    void bubbleSort(Node<T>*, int);

    template<typename T>
    void optimizedBubbleSort(Node<T>*, int);

    template<typename T>
    void insertionSort(Node<T>*, int);

    template<typename T>
    void selectionSort(Node<T>*, int);

    template<typename T>
    void optimizedSelectionSort(Node<T>*, int);

    template<typename T>
    void countingSort(Node<T>*, int);
}

#endif // SORTING_H
