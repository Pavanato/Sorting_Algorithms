#include <iostream>
#include <fstream>
#include "lists/linkedList.h"

using std::cout;
using std::endl;
using std::ifstream;


// Protótipo
void insertionSort(Node*, int);


int main()
{
    const int listSize = 10000;
    const int numLists = 100;
    
    std::ifstream inputFile("lists/randomLists.txt"); // Abre o arquivo de input
    
    if (inputFile.is_open()) {
        for (int i = 0; i < numLists; ++i) {
            Node* head = nullptr;
            readListFromFile(inputFile, &head, listSize); // Lê a lista do arquivo
            
            computeTime(head, listSize, insertionSort);
            cout << endl;
        }
        
        inputFile.close(); // Fecha o arquivo
    } else {
        cout << "Failed to open the input file." << endl;
    }


    return 0;
}


void insertionSort(Node* head, int iListLen)
{
    Node* insert = head;
    Node* inner = head->ptrNext;
    for (int iOuterLoop = 0; iOuterLoop < iListLen - 1; iOuterLoop++)
    {
        while (inner->ptrPrev != nullptr && inner->iPayload < inner->ptrPrev->iPayload)
        {
            swap(inner, inner->ptrPrev);
            inner = inner->ptrPrev;
        }
        insert = insert->ptrNext;
        inner = insert->ptrNext;
    }
}