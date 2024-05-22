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
    std::ofstream outputFile("test_output.txt");

    // Compute time for each sorting algorithm
    computeTime(Sorting::bubbleSort<int>, inputFile, outputFile, listSize, numLists);
    computeTime(Sorting::optimizedBubbleSort<int>, inputFile, outputFile, listSize, numLists);
    computeTime(Sorting::selectionSort<int>, inputFile, outputFile, listSize, numLists);
    computeTime(Sorting::optimizedSelectionSort<int>, inputFile, outputFile, listSize, numLists);
    computeTime(Sorting::insertionSort<int>, inputFile, outputFile, listSize, numLists);

    // close the input file
    inputFile.close();

    return 0;
}
