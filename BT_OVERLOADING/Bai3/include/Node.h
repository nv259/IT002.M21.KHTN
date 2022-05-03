#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        Node();
        Node(const int &, Node *);
        virtual ~Node();

        int data;
        Node *next;
    protected:

    private:

};

#endif // NODE_H
