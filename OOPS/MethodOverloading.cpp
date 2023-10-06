// Overloading increment and post-increment operators of a Integer class;

#include <bits/stdc++.h>
using namespace std;

class Integer
{

public:
    int x;
    Integer operator++()
    {
        Integer i;
        i.x = ++x;
        return i;
    }

    Integer operator++(int)
    {
        Integer i;
        i.x = x++;
        return i;
    }

    void setValue(int x)
    {
        this->x = x;
    }
};

int main()
{
    Integer obj;
    int x;
    cin >> x;
    obj.setValue(x);

    cout << ++obj.x << endl;
    cout << obj.x++ << endl;
    cout << obj.x;
}
