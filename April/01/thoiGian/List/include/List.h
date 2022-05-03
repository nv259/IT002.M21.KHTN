#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

class List
{
    public:
        List();
        virtual ~List();

        void push_back(int val);
        void push_front(int val);

        friend ostream& operator << (ostream &out, const List &L);
        friend istream& operator >> (istream &inp, List &L);

    protected:

    private:
        int LFront, LBack;
        int value[5000];
};

#endif // LIST_H
