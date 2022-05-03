#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    Queue q;
    for (int i = 0; i < 10; i++)
        q.push_back(i);
    q.push_back(10);

    for (int i = 0; i < 10; i++)
        q.pop_front();
    q.pop_front();

    return 0;
}
