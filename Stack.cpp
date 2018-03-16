#include "Stack.h"
#include <iostream>

using namespace std;


Stack::Stack(int size)
{
    maxSize = size;
}

template <class DataType>
Stack::~Stack()
{
    if(top == NULL)
        cout << "Empty Stack" << endl;
    else
    {
        StackNode<DataType>* temp = top;
        StackNode<DataType>* delete = temp;
        while(temp != NULL)//go until it finds null, we past the last node
        {
            deleter = temp;
            temp = temp->next;//move temp down the stack
            delete deleter;   //delete the node we past
        }
        
    }
}

template <class DataType>
void Stack::push(const DataType newNode)
{
    newNode->next = top;
    top = newNode;
}

template <class DataType>
void Stack::pop()
{
    StackNode<DataType>* deleter = top;
    top = top->next;
    delete deleter;
}

bool Stack::isEmpty()
{
    return (numNodes > 0);
}

bool Stack::isFull()
{
    return (numNodes >= maxSize);
}

template <class DataType>
DataType Stack::topStack() const
{
    return top->data;
}
