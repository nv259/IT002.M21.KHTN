#include    <iostream>

using namespace std;

class List
{
    public:
        List();
        ~List();

        void addFront(int);
        void addBack(int);

        friend ostream & operator << (ostream &, List);
        friend istream & operator >> (istream &, List &);

        int length();
        bool find_(int);
        void insertAfter(int, int);
        int numOdd();
        int numEven();
        void delete_(int);

    private:
        int LFront, LBack;
        int arr[2000];
};

List::List()
{
    LFront = LBack = 1000;
}

List::~List()
{
    // dtor
}

void List::addBack(int val)
{
    arr[LBack++] = val;
}

void List::addFront(int val)
{
    arr[--LFront] = val;
}

ostream & operator << (ostream &out, List p)
{
    for (int i = p.LFront; i < p.LBack; i++)
        out << p.arr[i] << " ";

    return out;
}

istream & operator >> (istream &inp, List &p)
{
    //
}

int List::length()
{
    return LBack - LFront;
}

bool List::find_(int val)
{
    for (int i = LFront; i < LBack; i++)
        if (arr[i] == val)
            return true;

    return false;
}

void List::insertAfter(int x, int y)
{
    for (int i = LFront; i < LBack; i++)
    {
        if (arr[i] == y)
        {
            LBack++;
            for (int j = i + 2; j < LBack; j++)
                arr[j] = arr[j - 1];
            arr[i + 1] = x;
            break;
        }
    }
}

int List::numEven()
{
    int result = 0;
    for (int i = LFront; i < LBack; i++)
        if (arr[i] % 2 == 0)
            result++;

    return result;
}

int List::numOdd()
{
    int result = 0;
    for (int i = LFront; i < LBack; i++)
        if (arr[i] % 2 == 1)
            result++;

    return result;
}

void List::delete_(int val)
{
    for (int i = LFront; i < LBack; i++)
    {
        if (arr[i] == val)
        {
            for (int j = i; j < LBack - 1; j++)
                arr[j] = arr[j + 1];
            LBack--;
            break;
        }
    }
}

int main()
{
    cout << "Menu: \n";
    cout << "0. Dung chuong trinh.\n";
    cout << "1. Them du lieu vao dau danh sach.\n";
    cout << "2. Them du lieu vao cuoi danh sach.\n";
    cout << "3. Xuat danh sach hien tai.\n";
    cout << "4. Tinh do dai danh sach.\n";
    cout << "5. Tim gia tri x co trong danh sach hay khong.\n";
    cout << "6. Chen gia tri x sau gia tri y trong danh sach.\n";
    cout << "7. Dem so luong gia tri chan, le trong danh sach.\n";
    cout << "8. Xoa mot phan tu x.\n";

    int option, x;
    List l;
    do
    {
        cin >> option;
        switch (option)
        {
            case 0:
                break;
            case 1:

                cout << "Nhap gia tri x can them: ";
                cin >> x;
                l.addFront(x);
                break;
            case 2:

                cout << "Nhap gia tri x can them: ";
                cin >> x;
                l.addBack(x);
                break;
            case 3:
                cout << l << "\n";
                break;
            case 4:
                cout << "Do dai danh sach: " << l.length() << "\n";
                break;
            case 5:

                cout << "Nhap gia tri x can tim: ";
                cin >> x;
                if (l.find_(x))
                    cout << "Co ton tai!\n";
                else
                    cout << "Khong ton tai!\n";
                break;
            case 6:
                int y;
                cout << "Nhap x, y: ";
                cin >> x >> y;
                l.insertAfter(x, y);
                break;
            case 7:
                cout << "So so chan: " << l.numEven() << "\n";
                cout << "So so le: " << l.numOdd() << "\n";
                break;
            default:

                cout << "Nhap gia tri x can xoa: ";
                cin >> x;
                l.delete_(x);
        }
    } while (option < 9 && option > 0);
    return 0;
}
