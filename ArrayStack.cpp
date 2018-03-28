#include "ArrayStack.h"
#include "Student.h"
#include <iostream>

using namespace std;

template <class DataType>
ArrayStack<DataType>::ArrayStack(int size)
{
    data = new DataType*[size];
}

template <class DataType>
ArrayStack<DataType>::~ArrayStack()
{
    if(top == NULL)
        cout << "ArrayStack is empty" << endl;
    else
    {
        ArrayStackNode<DataType>* temp = top;
        ArrayStackNode<DataType>* deleter = temp;
        while(temp != NULL)//go until it finds null, we past the last node
        {
            deleter = temp;
            temp = temp->next;//move temp down the stack
            delete deleter;   //delete the node we past
        }
        
    }
}

template <class DataType>
void ArrayStack<DataType>::push(const DataType d)
{
    if(!isFull())
    {
	cout<<"Pushing" << endl;
        ArrayStackNode<DataType>* newNode= new ArrayStackNode<DataType>();
        newNode->data = d;
        newNode->next = top;
        top = newNode;
        numNodes++;
    }else
        cout << "ArrayStack is full" << endl;
    cout<<"pushed" << endl;
}

template <class DataType>
void ArrayStack<DataType>::pop()
{
    if(!isEmpty())
    {
        //cout << "pop" << endl;
        ArrayStackNode<DataType>* deleter = top;
        top = top->next;
        delete deleter;
        numNodes--;
    }else
        cout << "ArrayStack is empty" << endl;
}
template <class DataType>
bool ArrayStack<DataType>::isEmpty() const
{
    return (numNodes <= 0);
}
template <class DataType>
bool ArrayStack<DataType>::isFull() const
{
    return (numNodes >= maxSize);
}

template <class DataType>
DataType ArrayStack<DataType>::topArrayStack() const
{
	if(top != NULL)
	{
    return top->data;
	}else
		cout << "Empty stack" << endl;
	return DataType();
}

template <>
Student ArrayStack<Student>::topArrayStack() const
{
	if(top != NULL)
	{
    	top->data.printStudent();   
    	return top->data;
	}else
		cout << "Empty stack" << endl;
	return Student();
}
template<>
int ArrayStack<int>::topArrayStack() const
{
	if(top != NULL)
	{
		cout << top->data << endl;    
		return top->data;
	}else
		cout << "Empty stack" << endl;
	return -1;
}
template <class DataType>
void ArrayStack<DataType>::printArrayStack()
{
    if(!isEmpty())
        {
        ArrayStackNode<DataType>* temp = top;
        //cout << "num " << numNodes << endl;
        while(temp != NULL)
        {
            //cout << temp->data << ", ";
            temp = temp->next;
        }
        cout << endl;
    }else
        cout << "Empty stack" << endl;
}

