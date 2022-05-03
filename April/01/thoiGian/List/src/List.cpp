#include "List.h"

List::List()
{
    //ctor
    LFront = 2500;
    LBack = 2500;
    fill(value, value + 5000, NULL);
}

List::~List()
{
    //dtor
}

void List::push_back(int val)
{
    value[++LBack] = val;
}

void List::push_front(int val)
{
    value[LFront--] = val;
}

ostream& operator << (ostream &out, const List &L)
{
    out << "List: ";
    for (int i = L.LFront + 1; i <= L.LBack; i++)
        out << L.value[i] << " ";
}

istream& operator >> (istream &inp, List &L)
{
    int n;
    cout << "Nhap so buoc thuc hien: ";
    inp >> n;

    cout << "0 X - Push X to the front of List\n1 Y - Push Y to the back of List\n";

    int key, x;

    for (int i = 0; i < n; i++)
    {
        inp >> key >> x;

        if (key) L.push_back(x);
        else L.push_front(x);
    }
}

