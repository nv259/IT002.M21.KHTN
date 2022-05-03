#include "DaThuc.h"

using namespace std;

int main()
{
    DaThuc p1, p2;
    cout << "DA THUC THU NHAT\n";
    cin >> p1;
    cout << "DA THUC THU HAI\n";
    cin >> p2;

    cout << "BAI 2 OVERLOADING - DA THUC\n";
    cout << "\t1. In da thuc thu nhat.\n";
    cout << "\t2. In da thuc thu hai.\n";
    cout << "\t3. Cong hai da thuc (p1 + p2).\n";
    cout << "\t4. Tru hai da thuc (p1 - p2).\n";
    cout << "\t5. Doi hai da thuc.\n";
    cout << "\t6. Nhap lai da thuc thu nhat.\n";
    cout << "\t7. Nhap lai da thuc thu hai.\n";
    cout << "\t8. Tinh gia tri P_1(X).\n";
    cout << "\t0. Ket thuc chuong trinh.\n";

    int option, x;
    cin >> option;
    DaThuc temp;

    while (option)
    {
        switch (option)
        {
            case 1:
                cout << "Da thuc thu nhat: " << p1 << "\n";
                break;
            case 2:
                cout << "Da thuc thu hai: " << p2 << "\n";
                break;
            case 3:
                cout << "Ket qua cua phep cong: ";
                cout << p1 + p2 << "\n";
                break;
            case 4:
                cout << "Ket qua cua phep tru: ";
                cout << p1 - p2 << "\n";
                break;
            case 5:
                cout << "DA THUC THU NHAT\n";
                cin >> p1;
                break;
            case 6:
                cout << "DA THUC THU HAI\n";
                cin >> p2;
                break;
            case 7:
                cout << "Da doi hai da thuc voi nhau !\n";
                temp = p2;
                p2 = p1;
                p1 = temp;
                break;
            case 8:
                cout << "Nhap gia tri cua x: ";
                cin >> x;
                cout << "P_1(" << x << ") = " << p1.tinhGiaTri(x) << "\n";
                break;
            default:
                break;
        }
        cin >> option;
    }

    return 0;
}
