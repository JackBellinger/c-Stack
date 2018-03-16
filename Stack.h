#ifndef STACK_H
#DEFINE STACK_H

template <class DataType>
struct StackNode
{
    DataType data;
    StackNode<DataType>* next;
};

template <class DataType>
class STACK_H
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


