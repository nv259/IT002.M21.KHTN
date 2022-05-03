#ifndef LINKLIST_H
#define LINKLIST_H

#include "Node.h"
#include <iostream>

using namespace std;

class LinkList
{
    public:
        LinkList();
        virtual ~LinkList();

        void _insert(int, int);
        void _delete(int);
        void _push_front(int);
        void _push_back(int);

        int _size();
        int _front();
        int _back();

        friend istream & operator >> (istream &, LinkList &);
        friend ostream & operator << (ostream &, LinkList);
    protected:

    private:
        Node *root;
};

#endif // LINKLIST_H
