#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    void f1(int x)
    {
        cout << "f1 Inside class A"
             << " Value = " << x << endl;
    }
    virtual void f2(int x)
    {
        cout << "f2 Inside class A"
             << "Incremented Value = " << x + 1 << endl;
    }
    virtual void f3()
    {
        cout << "f3 Inside class A" << endl;
    }
    virtual void f4(int x)
    {
        cout << "f4 Inside class A"
             << " Squared value = " << x * x << endl;
    }
};

class B : public A
{
public:
    void f1(int x)
    {
        cout << "f1 Inside class B"
             << " Squared Value = " << x * x << endl;
    }
    void f2(int x)
    {
        cout << "f2 Inside class B"
             << " Decremented Value = " << x - 1 << endl;
    }
    void f4(int x)
    {
        cout << "f4 Inside class B"
             << " Incremented Value = " << x + 1 << endl;
    }
    void f3()
    {
        cout << "f3 Inside class B" << endl;
    }
};

int main()
{

    int x, y;
    cin >> x >> y;

    int pointerType;
    cin >> pointerType;

    if (pointerType == 0)
    {
        B *p;
        B o2;
        p = &o2;
        p->f1(x); // Should call the f1 function from class B with the ouput as "f1 Inside class B Sqaured value = x*x"
        p->f2(y); // Should call the f2 function from class B with the ouput as "f2 Inside class B Decremented value = x-1"
        p->f3();  // Should call the f3 function from class B with the ouput as "f3 Inside class B"
        p->f4(x); // Should call the f4 function from class B with the ouput as "f4 Inside class B Incremented value = x+1"
    }
    else
    {
        A *p;
        B o2;
        p = &o2;
        p->f1(x); // Should call the f1 function from class A with the ouput as "f1 Inside class A Value = x"
        p->f2(y); // Should call the f2 function from class B with the ouput as "f2 Inside class B Decremented value = x-1"
        p->f3();  // Should call the f3 function from class B with the ouput as "f3 Inside class B"
        p->f4(x); // Should call the f4 function from class B with the ouput as "f4 Inside class B Incremented value = x+1"
    }
}
