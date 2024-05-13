#include <iostream>
#include <fstream>
#include "lists/linkedList.h"


using std::cout;
using std::endl;
using std::ifstream;


// Protótipos algorimos de ordenação
void bubbleSort(Node*, int);
void optimizedBubbleSort(Node*, int);

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
            
            computeTime(head, listSize, bubbleSort);
            cout << ",";
            computeTime(clone, listSize, optimizedBubbleSort);
            cout << endl;
        }
        
        inputFile.close(); // Fecha o arquivo
    } else {
        cout << "Failed to open the input file." << endl;
    }

    return 0;
}


// Implementação do algoritmo Bubble Sort
void bubbleSort(Node* head, int iListLen) 
{
    Node* current = head; // Ponteiro para o nó atual

    // Loop externo para percorrer a lista
    for (int i = 0; i < iListLen - 1; i++)
    {
        // Loop interno para comparar pares adjacentes e fazer as trocas necessárias
        for (int j = 0; j < iListLen - 1; j++)
        {
            // Verifica se o valor do nó atual é maior que o próximo nó na lista
            if (current->iPayload > current->ptrNext->iPayload)
            {
                swap(current, current->ptrNext); // Troca os nós
            }
            current = current->ptrNext; // Move para o próximo nó
        }
        current = head; // Reinicia a posição atual para o início da lista
    }
}

// Implementação do algoritmo Bubble Sort otimizado
void optimizedBubbleSort(Node* head, int iListLen) 
{
    Node* current = head; // Ponteiro para o nó atual
    bool bSwapped; // Flag para indicar se houve troca durante a iteração

    // Loop externo para percorrer a lista
    for (int i = 0; i < iListLen - 1; i++)
    {
        bSwapped = false; // Inicializa a flag de troca como falsa

        // Loop interno para comparar pares adjacentes e fazer as trocas necessárias
        for (int j = 0; j < iListLen - i - 1; j++)
        {
            // Verifica se o valor do nó atual é maior que o próximo nó na lista
            if (current->iPayload > current->ptrNext->iPayload)
            {
                swap(current, current->ptrNext); // Troca os nós
                bSwapped = true; // Define a flag de troca como verdadeira
            }
            
            current = current->ptrNext; // Move para o próximo nó
        }
        
        // Se não houve troca durante a iteração, a lista está ordenada e podemos sair do loop
        if (bSwapped == false)
        {
            break;
        }

        current = head; // Reinicia a posição atual para o início da lista
    }
}
