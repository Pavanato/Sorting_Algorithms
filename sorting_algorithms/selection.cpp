#include <iostream>
#include <fstream>
#include "lists/linkedList.h"

using std::cout;
using std::endl;
using std::ifstream;


// Protótipos algorimos de ordenação
void selectionSort(Node*, int);
void optimizedSelectionSort(Node*, int);

int main()
{
    const int listSize = 10000;
    const int numLists = 100;
    
    std::ifstream inputFile("lists/randomLists.txt"); // Abre o arquivo de input
    
    if (inputFile.is_open()) {
        for (int i = 0; i < numLists; ++i) {
            Node* head = nullptr;
            readListFromFile(inputFile, &head, listSize); // Lê a lista do arquivo
    
            Node* clone = nullptr;
            cloneList(head, &clone);
            
            computeTime(head, listSize, selectionSort);
            cout << ",";
            computeTime(clone, listSize, optimizedSelectionSort);
            cout << endl;
        }
        
        inputFile.close(); // Fecha o arquivo
    } else {
        cout << "Failed to open the input file." << endl;
    }

    return 0;
}

// Implementação do algoritmo Selection Sort
void selectionSort(Node* head, int iListLen) 
{
    Node* current = head; // Ponteiro para o nó atual
    Node* temp = head; // Ponteiro temporário para auxiliar nas trocas

    // Loop externo para percorrer a lista
    for (int i = 0; i < iListLen; i++)
    {
        temp = current; // Inicializa o ponteiro temporário como o nó atual

        // Loop interno para encontrar o menor elemento não ordenado
        for (int j = 0; j < iListLen - i; j++)
        {
            // Verifica se o valor do nó atual é maior que o valor do nó temporário
            if (current->iPayload > temp->iPayload)
            {
                swap(current, temp); // Troca os nós
            }
            temp = temp->ptrNext; // Move para o próximo nó temporário
        }
        current = current->ptrNext; // Move para o próximo nó atual
    }
}

// Implementação do algoritmo Selection Sort otimizado
void optimizedSelectionSort(Node* head, int iListLen)
{
    Node* current = head; // Ponteiro para o nó atual
    Node* temp; // Ponteiro temporário para auxiliar nas trocas
    Node* smallest; // Ponteiro para o menor elemento encontrado

    // Loop externo para percorrer a lista
    for (int i = 0; i < iListLen; i++)
    {
        smallest = current; // Define o menor elemento como o nó atual
        temp = current->ptrNext; // Inicializa o ponteiro temporário como o próximo nó

        // Loop interno para encontrar o menor elemento não ordenado
        for (int j = 0; j < iListLen - i - 1; j++)
        {
            // Verifica se o valor do nó atual é maior que o valor do nó temporário
            if (smallest->iPayload > temp->iPayload)
            {
                smallest = temp; // Atualiza o menor elemento encontrado
            }
            temp = temp->ptrNext; // Move para o próximo nó temporário
        }

        // Se o menor elemento encontrado for menor que o nó atual, realiza a troca
        if (smallest->iPayload < current->iPayload)
        {
            swap(smallest, current); // Troca os nós
        }
        
        current = current->ptrNext; // Move para o próximo nó atual
    }
}
