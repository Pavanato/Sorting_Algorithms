#include "lists/linkedList.h"
#include "sorting_algorithms/sorting.h"

using std::cout;
using std::endl;

int main() {
    const int listSize = 10000;
    const int numLists = 100;

    // input file
    std::ifstream inputFile("IOfiles/randomLists.txt");

    // test if the file is open
    if (!inputFile.is_open()) {
        cout << "Failed to open the input file." << endl;
        return 1;
    }

    // output file
    std::ofstream outputFile("./IOfiles/output2.txt");

    // test if the file is open
    if (!outputFile.is_open()) {
        cout << "Failed to open the output file." << endl;
        return 1;
    }

    // Compute time for each sorting algorithm
    computeTime(Sorting::bubbleSort<int>, inputFile, outputFile, listSize, numLists);
    computeTime(Sorting::optimizedBubbleSort<int>, inputFile, outputFile, listSize, numLists);
    computeTime(Sorting::selectionSort<int>, inputFile, outputFile, listSize, numLists);
    computeTime(Sorting::optimizedSelectionSort<int>, inputFile, outputFile, listSize, numLists);
    computeTime(Sorting::insertionSort<int>, inputFile, outputFile, listSize, numLists);
    computeTime(Sorting::countingSort<int>, inputFile, outputFile, listSize, numLists);

    // close the input file
    inputFile.close();

    cout << "###########################" << endl;

    cout << "Testing counting sort algorithm." << endl;

    // test counting sort with {1, 4, 1, 2, 7, 5, 2}
    Node<int>* head = nullptr;
    insertEnd(&head, 1);
    insertEnd(&head, 4);
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 7);
    insertEnd(&head, 5);
    insertEnd(&head, 2);

    cout << "Before sorting:" << endl;

    displayList(head);

    Sorting::countingSort(head, 7);

    cout << "After sorting:" << endl;

    displayList(head);
    
    return 0;
}
