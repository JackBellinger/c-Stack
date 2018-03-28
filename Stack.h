#ifndef STACK_H
#define STACK_H

#include <cstddef>

template <class DataType>
struct StackNode
{
    DataType data;
    StackNode<DataType>* next;
public:
    StackNode();
};

template <class DataType>
class Stack
{
private:
    StackNode<DataType>* top;
    int maxSize;
    int numNodes = 0;
public:
    Stack(int=10);
    ~Stack();
    bool isEmpty() const;
    bool isFull() const;
    void push(const DataType);
    void pop();
    DataType topStack() const;
    void printStack();
};
#endif
