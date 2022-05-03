#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue()
{
    //ctor
    length = 0;
    QFront = 0;
    QBack = -1;
}

Queue::~Queue()
{
    //dtor
}

int Queue::front()
{
    return list[QFront];
}

int Queue::back()
{
    return list[QBack];
}

int Queue::size()
{
    return length;
}

void Queue::push_back(int value)
{
    if (isFull())
    {
        cout << "List is already full\n";
        return;
    }

    cout << "Push " << value << "\n";
    list[length++] = value;
    QBack++;
}

void Queue::pop_front()
{
    if (isEmpty())
    {
        cout << "List is already empty\n";
        return;
    }

    cout << "Pop " << list[QFront] << "\n";
    for (int i = QFront; i < QBack; i++)
        list[i] = list[i+1];

    length--; QBack--;
}

bool Queue::isEmpty()
{
    return QBack < QFront;
}

bool Queue::isFull()
{
    return (length == 10);
}
