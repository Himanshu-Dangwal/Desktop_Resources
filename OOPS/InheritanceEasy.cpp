// Friend function queastion in inheritance
#include <bits/stdc++.h>
using namespace std;

class B;
class A
{
private:
    int a;

public:
    void setValue(int x) { a = x; }
    friend void fun(A, B);
};

class B
{
private:
    int b;

public:
    void setValue(int x) { b = x; }
    friend void fun(A, B);
};

void fun(A obj1, B obj2)
{
    cout << obj1.a << " " << obj2.b << endl;
}

int main()
{
    A obj1;
    int x, y;
    cin >> x >> y;
    obj1.setValue(x);
    B obj2;
    obj2.setValue(y);
    fun(obj1, obj2);
    return 0;
}