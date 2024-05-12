#include <iostream>
#include <chrono>
#include <vector>

using std::cout;
using std::endl;

// Lista duplamente encadeada
typedef struct Node
{
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

// Protótipos
Node* createNode(int);
void insertFront(Node**, int);
void insertEnd(Node**, int);
void displayList(Node*);
void displayHeadAndTail(Node*);
void computeTime(Node*, int, void (*)(Node*, int));
void generateRandomList(Node**, int);
void cloneList(Node*, Node**);
void swap(Node*, Node*);

Node* createNode(int iPayload) 
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->iPayload = iPayload;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;

    return temp;
}

void displayList(Node* node) 
{
    if (node == nullptr)
    {
        cout << "Lista vazia: Não é possível realizar displayList" << endl;
        return;
    }

    if (node->ptrPrev != nullptr)
    {
        cout << "Meio ou Fim da Lista: Não é possível realizar displayList" << endl;
        return;
    }

    Node* temp = node;

    cout << "Payload: ";

    //Percorremos a lista até seu fim (ptrNext do último nó é NULL)
    while (temp != nullptr)
    {
        cout << temp->iPayload << " ";
        temp = temp->ptrNext;
    }
    
    cout << endl;
}

void insertFront(Node** head, int iPayload) 
{
    Node* newNode = createNode(iPayload);
    
    if (*head != nullptr)
    {
        // newNode->ptrPrev = nullptr
        (*head)->ptrPrev = newNode;
        newNode->ptrNext = (*head);
        (*head) = newNode;
        return;
    }
    (*head) = newNode;
}

void insertEnd(Node** head, int iPayload) 
{
    Node* newNode = createNode(iPayload);

    if (*head == nullptr)
    {
        (*head) = newNode; // derreferenciando um ponteiro
        return;
    }

    Node* temp = (*head);

    //Percorre a lista
    while (temp->ptrNext != nullptr) temp = temp->ptrNext;

    newNode->ptrPrev =  temp; //newNode aponta para o fim da lista
    temp->ptrNext = newNode; //Antigo último elemento aponta para o novo nó
}

void displayHeadAndTail(Node* node)
{
    if (node == nullptr)
    {
        cout << "Lista vazia: Não é possível realizar displayHead" << endl;
        return;
    }

    if (node->ptrPrev != nullptr)
    {
        cout << "Meio ou Fim da Lista: Não é possível realizar displayHead" << endl;
        return;
    }

    Node* temp = node;

    cout << "Head ... Tail: ";

    // Printa os 5 primeiros elementos da lista
    for (int i = 0; i < 5; i++)
    {
        cout << temp->iPayload << " ";
        temp = temp->ptrNext; 
    }

    cout << "... ";

    // Percorremos a lista até seu fim para obter o endereço do último elemento (ptrNext do último nó é NULL)
    while (temp->ptrNext != nullptr)
    {
        temp = temp->ptrNext;
    }
    
    // Volta 5 elementos
    for (int i = 0; i < 4; i++)
    {
        temp = temp->ptrPrev; 
    }

    // Printa os 5 últimos elementos da lista
    for (int i = 0; i < 5; i++)
    {
        cout << temp->iPayload << " ";
        temp = temp->ptrNext; 
    }

    cout << endl;
}

// Computa o tempo de execução de um algoritmo de ordenação
void computeTime(Node* head, int iListLen, void (*sortFunc)(Node*, int)) 
{
    auto start = std::chrono::high_resolution_clock::now();
    sortFunc(head, iListLen);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    cout << elapsed.count();
}

// Gera listas aleatórias
void generateRandomList(Node** head, int iListLen) 
{
    for (int i = 0; i < iListLen; i++)
    {
        insertEnd(head, rand() % 10000);
    }
}

// cria um clone da lista
void cloneList(Node* head, Node** clonedHead) 
{
    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr)
    {
        insertEnd(clonedHead, temp->iPayload);
        temp = temp->ptrNext;
    }
}

// algoritmo que troca os valores de dois nós
void swap(Node* node1, Node* node2) 
{
    // salva o valor do node1
    int temp = node1->iPayload;

    // troca os valores
    node1->iPayload = node2->iPayload;
    node2->iPayload = temp;
}

void readListFromFile(std::ifstream& inputFile, Node** head, int listSize)
{
    for (int i = 0; i < listSize; i++)
    {
        int value;
        inputFile >> value;
        insertEnd(head, value);
    }
}