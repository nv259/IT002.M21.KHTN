#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack()
{
    //ctor
    length = 0;
}

Stack::~Stack()
{
    //dtor
}

void Stack::push(int value)
{
    if (isFull())
    {
        cout << "List is already full!\n";
        return;
    }

    // cout << "Push " << value << "\n";
    list[length++] = value;
}

void Stack::pop()
{
    if (isEmpty())
    {
        cout << "List is already empty!\n";
        return;
    }

    // cout << "Pop " << list[length - 1] << "\n";
    length--;
}

int Stack::top()
{
    return list[length - 1];
}

int Stack::Size()
{
    return length;
}

bool Stack::isFull()
{
    return length == 100;
}

bool Stack::isEmpty()
{
    return length == 0;
}

