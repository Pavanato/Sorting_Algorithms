#include "lists/linkedList.h"
#include "sorting_algorithms/sorting.h"
#include "tree/binary_search_tree.h"

using std::cout;
using std::endl;

int main() {
    /*
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
    */

   // Parte 3 do Trabalho: Monitorar o desempenho de busca em árvore utilizando DFS e BFS
    // Parte 4 do Trabalho: Monitorar o desempenho de criação de listas
    // Parte 5 do Trabalho: Monitorar o desempenho de criação de árvores

    // Testing time for creating lists and trees with the same elements

    const int listSize = 10000;
    const int numLists = 100;

    // output file
    std::ofstream outputFile1("./IOfiles/list_tree_time.txt");
    std::ofstream outputFile2("./IOfiles/search_time.txt");

    for (int i = 0; i < numLists; i++)
    {
        // Generate random array that will be used to create lists and trees
        int randomArray[listSize];

        for (int i = 0; i < listSize; i++)
        {
            randomArray[i] = rand() % 10000 + 1;
        }

        // Compute time for creating lists
        auto start = std::chrono::high_resolution_clock::now();
        Node<int>* head = nullptr;
        for (int i = 0; i < listSize; ++i) {
            insertFront(&head, randomArray[i]);
        }
        auto end = std::chrono::high_resolution_clock::now();

        auto list_elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

        // Compute time for creating trees
        start = std::chrono::high_resolution_clock::now();
        BinaryTree::Node<int>* root = nullptr;
        for (int i = 0; i < listSize; ++i) {
            root = BinaryTree::insertTreeNode(root, randomArray[i]);
        }
        end = std::chrono::high_resolution_clock::now();

        auto tree_elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

        outputFile1 << list_elapsed.count() << "," << tree_elapsed.count() << endl;

        // Choose random element to search in the tree
        int randomElement = randomArray[rand() % listSize];

        // Compute time for searching the element in the tree using DFS
        start = std::chrono::high_resolution_clock::now();
        
        end = std::chrono::high_resolution_clock::now();

        auto dfs_elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

        // Compute time for searching the element in the tree using BFS
        start = std::chrono::high_resolution_clock::now();
        BinaryTree::bfsSearch(root, randomElement);
        end = std::chrono::high_resolution_clock::now();

        auto bfs_elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

        outputFile2 << dfs_elapsed.count() << "," << bfs_elapsed.count() << endl;
    }
    
    return 0;
    }