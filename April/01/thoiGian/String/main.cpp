#include <iostream>
#include "String.h"

using namespace std;

int main()
{
    String str1, str2;
    cin >> str1;
    cout << "1st string: " << str1;
    cout << endl;

    cin >> str2;
    cout << "2nd string: " << str2;
    cout << endl;

    str1.reverse();
    cout << "Reverse 1st string: " << str1;
    cout << endl;

    cout << str1;
    cout << " + ";
    cout << str2;
    cout << " = ";
    String str1_2 = str1 + str2;
    cout << str1_2;

    return 0;
}
