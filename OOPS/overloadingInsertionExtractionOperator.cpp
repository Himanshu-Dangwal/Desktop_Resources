#include <bits/stdc++.h>
using namespace std;

class Complex
{
private:
    int a, b;

public:
    friend ostream &operator<<(ostream &, Complex);
    friend istream &operator>>(istream &, Complex &);
};

ostream &operator<<(ostream &dout, Complex c)
{
    cout << c.a << " " << c.b << endl;
    return dout;
}

istream &operator>>(istream &din, Complex &c)
{
    din >> c.a >> c.b;
    return din;
}

int main()
{

    Complex c;
    cin >> c;  // operator>>(cin,c);
    cout << c; // operator<<(cout,c);s
    return 0;
}