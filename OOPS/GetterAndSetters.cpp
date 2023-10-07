#include <bits/stdc++.h>
using namespace std;

class RegularPentagon
{
    int side, perimeter;

public:
    int getPerimeter()
    {
        return this->side * 5;
    }

    void setSide(int side)
    {
        this->side = side;
    }

    int getSide()
    {
        return this->side;
    }
};

int main()
{
    RegularPentagon pent;

    int x;
    cin >> x;
    pent.setSide(x);
    cout << pent.getSide() << endl;
    cout << pent.getPerimeter();
}