
#include "binary_search_tree.h"

namespace BinaryTree
{
    template<typename T>
    Node<T>* createTreeNode(T Data)
    {
        Node<T>* tmp = (Node<T>*) malloc(sizeof(Node<T>));
    
        if (tmp == nullptr)
        {
            cerr << "Erro em createNode: malloc" << endl;
            exit(1);
        }
        
        tmp->Payload = Data;
        tmp->ptrLeft = nullptr;
        tmp->ptrRight = nullptr;
        
        return tmp;
    }

    template<typename T>
    Node<T>* insertTreeNode(Node<T>* startingNode, T Data)
    {
        if(startingNode == nullptr) return createTreeNode(Data);
        
        if(Data < startingNode->Payload)
        {
            startingNode->ptrLeft = insertTreeNode(startingNode->ptrLeft, Data);
        }
        else
        {
            startingNode->ptrRight = insertTreeNode(startingNode->ptrRight, Data);
        }

        return createTreeNode(Data);
    }
    
    
    template<typename T>
    Node<T>* dfsSearch(Node<T>* startingNode, T Data)
    {
        if (startingNode == nullptr) return nullptr;
        else if (startingNode->Payload == Data) return startingNode;
        else if (Data < startingNode->Payload) return dfsSearch(startingNode->ptrLeft, Data);
        else return dfsSearch(startingNode->ptrRight, Data);
    }

    template<typename T>
    Node<T>* bfsSearch(Node<T>* startingNode, T Data)
    {
        if (startingNode == nullptr) return nullptr;

        // creates doubly linked list
        LinkedList::Node<Node<T>*>* ptrQueue = nullptr;
        LinkedList::insertEnd(&ptrQueue, startingNode); // Add the starting node to the queue

        // creates a node to store the current node
        Node<T>* ptrCurrent = nullptr;
        while (ptrQueue != nullptr)
        {
            ptrCurrent = ptrQueue->Payload;
            
            LinkedList::removeFront(&ptrQueue);

            if (ptrCurrent->Payload == Data) return ptrCurrent;
            
            if (ptrCurrent->ptrLeft != nullptr) LinkedList::insertEnd(&ptrQueue, ptrCurrent->ptrLeft);
            if (ptrCurrent->ptrRight != nullptr) LinkedList::insertEnd(&ptrQueue, ptrCurrent->ptrRight);
        }

        return nullptr; // Return nullptr if data is not found
    }

    template<typename T>
    Node<T>* lesserLeaf(Node<T>* startingNode)
    {
        Node<T>* ptrCurrent = startingNode;
        
        while (ptrCurrent && ptrCurrent->ptrLeft != nullptr) ptrCurrent = ptrCurrent->ptrLeft;
        
        return ptrCurrent;
    }

    template<typename T>
    int treeHeight(Node<T>* startingNode)
    {
        if (startingNode == nullptr) return 0;
        else
        {
            int iLeftHeight = treeHeight(startingNode->ptrLeft);
            int iRightHeight = treeHeight(startingNode->ptrRight);
            
            return max(iLeftHeight, iRightHeight) + 1;
        }
    }

// Explicit instantiation for int
template Node<int>* createTreeNode(int);
template Node<int>* insertTreeNode(Node<int>*, int);
template Node<int>* bfsSearch(Node<int>*, int);
template Node<int>* dfsSearch(Node<int>*, int);
template Node<int>* lesserLeaf(Node<int>*);
template int treeHeight(Node<int>*);
}
