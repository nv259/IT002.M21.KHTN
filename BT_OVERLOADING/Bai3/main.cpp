#include "LinkList.h"

using namespace std;

int main()
{
    LinkList p;
    cout << "BAI 3 OVERLOADING - LINKLIST\n";
    cout << "MENU:\n";
    cout << "\t1. Nhap list gom N phan tu.\n";
    cout << "\t2. Xuat list.\n";
    cout << "\t3. Them vao dau list.\n";
    cout << "\t4. Them vao cuoi list.\n";
    cout << "\t5. Them vao vi tri bat ki.\n";
    cout << "\t6. Xoa tat ca cac phan tu bang gia tri cho truoc.\n";
    cout << "\t7. Kich thuoc cua list.\n";
    cout << "\t8. Phan tu dau.\n";
    cout << "\t9. Phan tu cuoi.\n";
    cout << "\t0. Ket thuc chuong trinh.\n";

    int option, val, index;
    cin >> option;
    while (option)
    {
        switch (option)
        {
            case 1:
                cin >> p;
                cout << p << "\n";
                break;
            case 2:
                cout << p << "\n";
                break;
            case 3:
                cout << "Nhap gia tri can them: ";
                cin >> val;
                p._push_front(val);
                break;
            case 4:
                cout << "Nhap gia tri can them: ";
                cin >> val;
                p._push_back(val);
                break;
            case 5:
                cout << "Nhap gia tri can them: ";
                cin >> val;
                cout << "Nhap vi tri muon them: ";
                cin >> index;
                p._insert(index, val);
                break;
            case 6:
                cout << "Nhap gia tri can xoa: ";
                cin >> val;
                p._delete(val);
                break;
            case 7:
                cout << "Kich thuoc cua list: " << p._size() << "\n";
                break;
            case 8:
                cout << "Phan tu dau cua list: " << p._front() << "\n";
                break;
            case 9:
                cout << "Phan tu cuoi cung cua list: " << p._back() << "\n";
            default:
                break;
        }

        cin >> option;
    }

    return 0;
}
