#include    <bits/stdc++.h>

using namespace std;

class complex_num {
    double x, y;
    
    public:
        void cin_data() {
            cin >> x >> y;
        }

        void print() {
            cout << x << ' ' << y << '\n';
        }

        complex_num() { x = 0; y = 0; };
        complex_num(int x, int y = 0) { this->x = x; this->y = y; };

        int getX() {
            return x;
        }

        int getY() {
            return y;
        }

        void setX(int x) {
            this->x = x;
        }

        void setY(int y) {
            this->y = y;
        }

        complex_num operator+ (complex_num a) {
            complex_num result;
            result.x = x + a.x;
            result.y = y + a.y;
            return result;
        }

        complex_num operator- (complex_num a) {
            return (x - a.x, y - a.y);
        }

        complex_num operator* (complex_num a) {
            complex_num result;
            result.x = x * a.x - y * a.y;
            result.y = x * a.y + y * a.x;
            return result;
        } 

        complex_num operator/ (complex_num a) {
            if (a.x == 0 && a.y == 0) 
            {
                cout << "Can't calculate";
                return (NULL, NULL);
            }

            complex_num result;
            result.x = (x * a.x + y * a.y) / (a.x * a.x + a.y * a.y);
            result.y = (a.x * y - x * a.y) / (a.x * a.x + a.y * a.y);
            return result;
        }
};

int main() {
    complex_num a, b;
    a.cin_data();
    b.cin_data();

    complex_num ab;
   
    ab = a + b;
    ab.print();

    ab = a - b;
    ab.print();

    ab = a * b;
    ab.print();

    ab = a / b;
    ab.print(); 

    return 0;
}