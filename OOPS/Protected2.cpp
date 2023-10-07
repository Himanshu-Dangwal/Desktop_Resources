#include <bits/stdc++.h>
using namespace std;

class A
{
protected:
    int val;

public:
    void setVal(int val)
    {
        this->val = val;
    }
};

class B : public A
{
public:
    void showVal()
    {
        cout << this->val;
    }
    void setValue()
    {
        this->val = 25;
    }
};

int main()
{
    B obj;
    int x;
    cin >> x;
    obj.setVal(x);
    obj.showVal();
    obj.setValue();
    obj.showVal();
    return 0;
}
