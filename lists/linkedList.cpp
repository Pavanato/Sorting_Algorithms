#include "linkedlist.h"

namespace LinkedList
{ 
template<typename T>
Node<T>* createNode(T Payload) 
{
    Node<T>* temp = (Node<T>*) malloc(sizeof(Node<T>));
    temp->Payload = Payload;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;

    return temp;
}

template<typename T>
void displayList(Node<T>* node) 
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

    Node<T>* temp = node;

    cout << "Payload: ";

    // Traverse the list
    while (temp != nullptr)
    {
        cout << temp->Payload << " ";
        temp = temp->ptrNext;
    }
    
    cout << endl;
}

template<typename T>
void insertFront(Node<T>** head, T Payload) 
{
    Node<T>* newNode = createNode(Payload);
    
    // If the list is not empty
    if (*head != nullptr)
    {
        (*head)->ptrPrev = newNode;
        newNode->ptrNext = (*head);
        (*head) = newNode;
        return;
    }
    (*head) = newNode;
}

template<typename T>
void insertEnd(Node<T>** head, T Payload) 
{
    Node<T>* newNode = createNode(Payload);

    // If the list is empty
    if (*head == nullptr)
    {
        (*head) = newNode;
        return;
    }

    Node<T>* temp = (*head);

    // Find the last node
    while (temp->ptrNext != nullptr) temp = temp->ptrNext;

    newNode->ptrPrev =  temp;
    temp->ptrNext = newNode;
}

template<typename T>
void displayHeadAndTail(Node<T>* node)
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

    Node<T>* temp = node;

    cout << "Head ... Tail: ";

    for (int i = 0; i < 5; i++)
    {
        cout << temp->Payload << " ";
        temp = temp->ptrNext; 
    }

    cout << "... ";

    while (temp->ptrNext != nullptr)
    {
        temp = temp->ptrNext;
    }
    
    for (int i = 0; i < 4; i++)
    {
        temp = temp->ptrPrev; 
    }

    for (int i = 0; i < 5; i++)
    {
        cout << temp->Payload << " ";
        temp = temp->ptrNext; 
    }

    cout << endl;
}

template<typename T>
void generateRandomList(Node<T>** head, int iListLen) 
{
    for (int i = 0; i < iListLen; i++)
    {
        insertEnd(head, rand() % 100);
    }
}

template<typename T>
void cloneList(Node<T>* head, Node<T>** clonedHead) 
{
    Node<T>* temp = head;

    // Traverse the list
    while (temp != nullptr)
    {
        insertEnd(clonedHead, temp->Payload);
        temp = temp->ptrNext;
    }
}

template<typename T>
void swap(Node<T>* node1, Node<T>* node2) 
{
    // Swap the Payloads of the two nodes
    T temp = node1->Payload;
    node1->Payload = node2->Payload;
    node2->Payload = temp;
}

template<typename T>
void readListFromFile(std::ifstream& inputFile, Node<T>** head, int listSize)
{
    for (int i = 0; i < listSize; i++)
    {
        // Read the value from the file and insert it at the end of the list
        T value;
        inputFile >> value;
        insertEnd(head, value);
    }

    // Reset the file pointer to the beginning of the file
    inputFile.clear();
    inputFile.seekg(0, std::ios::beg);
}

template<typename T>
void computeTimeAux(Node<T>* head, int iListLen, void (*sortFunc)(Node<T>*, int), std::ofstream& outputFile) 
{
    // Compute the time taken to sort the list
    auto start = std::chrono::high_resolution_clock::now();
    sortFunc(head, iListLen);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    outputFile << elapsed.count() << ",";
}

template<typename T>
void computeTime(void (*sortFunc)(Node<T>*, int), std::ifstream& inputFile, std::ofstream& outputFile, const int iListLen, const int iNumLists) 
{       
    if (inputFile.is_open()) {
        // Test the sorting algorithm with multiple lists
        for (int i = 0; i < iNumLists; ++i) {
            Node<T>* head = nullptr;
            readListFromFile(inputFile, &head, iListLen);
            
            // Compute the time taken to sort the list
            computeTimeAux(head, iListLen, sortFunc, outputFile);
        }
        
        // Remove the last comma from the file
        outputFile.seekp(-1, std::ios_base::end);
        outputFile << endl;
    } else {
        cout << "Failed to open the input file." << endl;
    }
}

// Explicit instantiation for int
template void insertFront<int>(Node<int>**, int);
template void insertEnd<int>(Node<int>**, int);
template void displayList<int>(Node<int>*);
template void displayHeadAndTail<int>(Node<int>*);
template void generateRandomList<int>(Node<int>**, int);
template void cloneList<int>(Node<int>*, Node<int>**);
template void swap<int>(Node<int>*, Node<int>*);
template void readListFromFile<int>(std::ifstream&, Node<int>**, int);
template void computeTimeAux<int>(Node<int>*, int, void (*sortFunc)(Node<int>*, int), std::ofstream&);
template void computeTime<int>(void (*sortFunc)(Node<int>*, int), std::ifstream&, std::ofstream&, const int, const int);
}