#include "Stack.h"
#include <iostream>

using namespace std;

template <class DataType>
Stack<DataType>::Stack(int size)
{
    maxSize = size;
}

template <class DataType>
Stack<DataType>::~Stack()
{
    if(top == NULL)
        cout << "Stack is empty" << endl;
    else
    {
        StackNode<DataType>* temp = top;
        StackNode<DataType>* deleter = temp;
        while(temp != NULL)//go until it finds null, we past the last node
        {
            deleter = temp;
            temp = temp->next;//move temp down the stack
            delete deleter;   //delete the node we past
        }
        
    }
}

template <class DataType>
void Stack<DataType>::push( DataType* d)
{
    if(!isFull())
    {
        StackNode<DataType>* newNode= new StackNode<DataType>();
        newNode->data = d;
        newNode->next = top;
        top = newNode;
        numNodes++;
    }else
        cout << "Stack is full" << endl;
}

template <class DataType>
void Stack<DataType>::pop()
{
    if(!isEmpty())
    {
        //cout << "pop" << endl;
        StackNode<DataType>* deleter = top;
        top = top->next;
        delete deleter;
        numNodes--;
    }else
        cout << "Stack is empty" << endl;
}
template <class DataType>
bool Stack<DataType>::isEmpty() const
{
    return (numNodes <= 0);
}
template <class DataType>
bool Stack<DataType>::isFull() const
{
    return (numNodes >= maxSize);
}

template <class DataType>
DataType Stack<DataType>::topStack() const
{
    return top->data;
}

template <class DataType>
void Stack<DataType>::printStack()
{
    if(!isEmpty())
        {
        StackNode<DataType>* temp = top;
        //cout << "num " << numNodes << endl;
        while(temp != NULL)
        {
            cout << temp->data << ", ";
            temp = temp->next;
        }
        cout << endl;
    }else
        cout << "Empty stack" << endl;
}
