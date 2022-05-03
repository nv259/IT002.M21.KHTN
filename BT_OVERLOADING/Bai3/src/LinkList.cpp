#include "LinkList.h"

LinkList::LinkList()
{
    //ctor
    root = NULL;
}

LinkList::~LinkList()
{
    //dtor
}

void LinkList::_insert(int index, int val)
{
    if (root == NULL)
    {
        Node *temp = new Node(val, NULL);
        root = temp;
    }
    Node *cur = root;
    for (int i = 0; i < index - 1; i++)
    {
        if (cur == NULL)
        {
            Node *temp = new Node();
            temp->data = val;
            temp->next = NULL;
            cur = temp;
            return;
        }

        cur = cur->next;
    }

    Node *temp = new Node;
    temp->data = val;
    temp->next = cur->next;
    cur->next = temp;
}

void LinkList::_delete(int val)
{
    while (root != NULL && root->data == val)
        root = root->next;
    Node *cur = root;

    for (int i = 0; cur->next != NULL; i++)
    {
        if (cur->next->data == val)
            cur->next = cur->next->next;

        cur = cur->next;
    }
}

void LinkList::_push_front(int val)
{
    _insert(0, val);
}

void LinkList::_push_back(int val)
{
    if (root == NULL)
    {
        Node *temp = new Node(val, NULL);
        root = temp;
        return;
    }

    Node *cur = root;
    for (int i = 0; cur->next != NULL; i++)
        cur = cur->next;

    Node *temp = new Node(val, NULL);
    cur->next = temp;
}

int LinkList::_size()
{
    int result = 0;
    Node *cur = root;
    for (int i = 0; cur != NULL; i++)
    {
        result++;
        cur = cur->next;
    }
    return result;
}

int LinkList::_front()
{
    return root->data;
}

int LinkList::_back()
{
    Node *cur = root;
    for (int i = 0; cur->next != NULL; i++)
        cur = cur->next;
    return cur->data;
}

istream & operator >> (istream &inp, LinkList &p)
{
    int n, val;
    cout << "Nhap so phan tu: ";
    inp >> n;

    for (int i = 0; i < n; i++)
    {
        inp >> val;
        p._push_back(val);
    }

    return inp;
}

ostream & operator << (ostream &out, LinkList p)
{
    Node *cur = p.root;

    for (; cur != NULL; cur = cur->next)
        out << cur->data << " ";

    return out;
}
