#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <cstddef>

template <class DataType>
class ArrayStack
{
private:
    DataType*[] data;
    int front = 0;
	int back = 0;
    int numNodes = 0;
public:
    ArrayStack(int=10);
    ~ArrayStack();
    bool isEmpty() const;
    bool isFull() const;
    void push(const DataType);
    void pop();
    DataType topStack() const;
    void printStack();
};
#endif
