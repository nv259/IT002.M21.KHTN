#include "DaThuc.h"
#include <algorithm>

DaThuc::DaThuc()
{
    //ctor
}

DaThuc::~DaThuc()
{
    //dtor
}

float _pow(float a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;

    float temp = _pow(a, b / 2);
    temp *= temp;

    return (b % 2) ? temp * a : temp;
}

float DaThuc::tinhGiaTri(float x)
{
    float result = 0;
    for (auto arr_i : arr)
    {
        int n = arr_i.first;
        float a = arr_i.second;

        result += a * _pow(x, n);
    }

    return result;
}

DaThuc operator + (const DaThuc &p1, const DaThuc &p2)
{
    DaThuc result = p1;
    int cc = 0;
    vector <pair<int, float>>::iterator it = result.arr.begin();

    for (auto arr_p2 : p2.arr)
    {
        int n = arr_p2.first;
        float a = arr_p2.second;

        while (cc <= p1.arr.size())
        {
            if (n > result[cc].first)
            {
                result.arr.insert(it + cc, {n, a});
                break;
            }

            if (n == result[cc].first)
            {
                result[cc].second += a;
                break;
            }

            cc++;
        }

        if (result[result.arr.size() - 1].first > n)
            result.arr.push_back({n, a});
    }

    return result;
}

/* DaThuc DaThuc::operator-()
{
    DaThuc result;

    for (auto arr_i : arr)
        result.arr.push_back({arr_i.first, -arr_i.second});
    return result;
} */

DaThuc operator - (const DaThuc &p)
{
    DaThuc result;
    for (auto arr_i : p.arr)
        result.arr.push_back({arr_i.first, -arr_i.second});
    return result;
}

DaThuc operator - (const DaThuc &p1, const DaThuc &p2)
{
    DaThuc temp = -p2;
    return DaThuc(p1 + temp);
}

istream &operator >> (istream &inp, DaThuc &p)
{
    p.arr.clear();
    int n;
    cout << "\tNhap n: ";
    inp >> n;
    cout << "\tP(X) = ";
    for (int i = 1; i < n; i++)
        cout << "a" << i << "*x^" << n - i + 1 << " + ";
    cout << "a" << n << "*x +" << "a" << n + 1;
    cout << "\n";

    for (int i = 1; i <= n + 1; i++)
    {
        float a;
        cout << "\tNhap a" << i << ": ";
        inp >> a;

        if (a != 0)
            p.arr.push_back({n - i + 1, a});
    }

    return inp;
}

ostream &operator << (ostream &out, DaThuc p)
{
    if (p.arr.empty())
    {
        out << "Chua co gia tri";
        return out;
    }

    out << "P(X) = ";
    out << p[0].second;
    if (p[0].first == 1) out << "x";
    if (p[0].first > 1) out << "x^" << p[0].first;

    for (int i = 1; i < p.arr.size(); i++)
    {
        int n = p[i].first;
        float a = p[i].second;

        if (a < 0)
        {
            cout << " -";
            a = abs(a);
        }
        else cout << " +";

        cout << ' ' << a;

        if (n == 0) continue;
        if (n == 1) cout << "x";
        else cout << "x^" << n;
    }
    return out;
}

pair<int, float> &DaThuc::operator [] (int i)
{
    return arr[i];
}
