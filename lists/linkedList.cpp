#include "linkedList.h"

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
        cout << "Empty list: Unable to perform displayList" << endl;
        return;
    }

    if (node->ptrPrev != nullptr)
    {
        cout << "Middle or End of the List: Unable to perform displayList" << endl;
        return;
    }

    Node* temp = node;

    cout << "Payload: ";

    // Traverse the list until the end (ptrNext of the last node is NULL)
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
        (*head) = newNode; // Dereference the head pointer to store the address of the newNode
        return;
    }

    Node* temp = (*head);

    // Traverse the list
    while (temp->ptrNext != nullptr) temp = temp->ptrNext;

    newNode->ptrPrev =  temp; // newNode points to the last element
    temp->ptrNext = newNode; // Old last element points to the newNode
}

void displayHeadAndTail(Node* node)
{
    if (node == nullptr)
    {
        cout << "Empty list: Unable to perform displayHeadAndTail" << endl;
        return;
    }

    if (node->ptrPrev != nullptr)
    {
        cout << "Middle or End of the List: Unable to perform displayHeadAndTail" << endl;
        return;
    }

    Node* temp = node;

    cout << "Head ... Tail: ";

    // Display the first 5 elements of the list
    for (int i = 0; i < 5; i++)
    {
        cout << temp->iPayload << " ";
        temp = temp->ptrNext; 
    }

    cout << "... ";

    // Traverse the list until the end (ptrNext of the last node is NULL)
    while (temp->ptrNext != nullptr)
    {
        temp = temp->ptrNext;
    }
    
    // Retrieve the last 5 elements of the list
    for (int i = 0; i < 4; i++)
    {
        temp = temp->ptrPrev; 
    }

    // Display the last 5 elements of the list
    for (int i = 0; i < 5; i++)
    {
        cout << temp->iPayload << " ";
        temp = temp->ptrNext; 
    }

    cout << endl;
}

// Generate a random list of integers
void generateRandomList(Node** head, int iListLen) 
{
    for (int i = 0; i < iListLen; i++)
    {
        insertEnd(head, rand() % 10000);
    }
}

// Creates a copy of the list
void cloneList(Node* head, Node** clonedHead) 
{
    Node* temp = head;

    while (temp != nullptr)
    {
        insertEnd(clonedHead, temp->iPayload);
        temp = temp->ptrNext;
    }
}

// Algorithm that swaps the values of two nodes
void swap(Node* node1, Node* node2) 
{
    // salva o valor do node1
    int temp = node1->iPayload;

    // troca os valores
    node1->iPayload = node2->iPayload;
    node2->iPayload = temp;
}

// Creates a list of integers from a file
void readListFromFile(std::ifstream& inputFile, Node** head, int listSize)
{
    for (int i = 0; i < listSize; i++)
    {
        int value;
        inputFile >> value;
        insertEnd(head, value);
    }

    // Set the read position to the beginning of the file
    inputFile.clear();
    inputFile.seekg(0, std::ios::beg);
}

// Next two functions are used to compute the time taken by the sorting algorithms
void computeTimeAux(Node* head, int iListLen, void (*sortFunc)(Node*, int), std::ofstream& outputFile) 
{
    auto start = std::chrono::high_resolution_clock::now();
    sortFunc(head, iListLen);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    outputFile << elapsed.count() << ",";
}

void computeTime(void (*sortFunc)(Node*, int), std::ifstream& inputFile, std::ofstream& outputFile, const int iListLen, const int iNumLists) 
{       
    if (inputFile.is_open()) {
        for (int i = 0; i < iNumLists; ++i) {
            Node* head = nullptr;
            readListFromFile(inputFile, &head, iListLen); // Read the list from the file
            
            computeTimeAux(head, iListLen, sortFunc, outputFile); // Compute the time taken by the sorting algorithm
        }
        
        // Remove the last comma and write a newline
        outputFile.seekp(-1, std::ios_base::end);
        outputFile << endl;
    } else {
        cout << "Failed to open the input file." << endl;
    }
}
