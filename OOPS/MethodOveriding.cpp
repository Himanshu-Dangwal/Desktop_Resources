#include <bits/stdc++.h>
using namespace std;

class Shape
{
protected:
    int r;

public:
    virtual int getArea()
    {
        return 6 * r * r;
    }

    void setValue(int r)
    {
        this->r = r;
    }
};

class Rectangle : public Shape
{
public:
    int getArea()
    {
        return this->r * this->r;
    }
};

int main()
{

    int type;
    cin >> type;

    if (type == 0)
    {
        Shape *p;
        Rectangle obj;
        p = &obj;

        int r;
        cin >> r;

        p->setValue(r);
        cout << p->getArea();
    }
    else
    {
        Shape *p;
        Shape obj;
        p = &obj;

        int r;
        cin >> r;

        p->setValue(r);
        cout << p->getArea();
    }
}