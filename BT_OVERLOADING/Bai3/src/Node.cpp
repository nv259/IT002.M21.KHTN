#include "Node.h"
#include <cstddef>

Node::Node()
{
    //ctor
}

Node::~Node()
{
    //dtor
}

Node::Node(const int &val, Node *p)
{
    data = val;
    next = p;
}
