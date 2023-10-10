#include <bits/stdc++.h>
using namespace std;

class Prime
{
private:
    int a;

public:
    void setA(int a)
    {
        this->a = a;
    }
    friend bool checkPrime(Prime &p);
};

bool checkPrime(Prime &c)
{
    int n = c.a;
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    Prime p;
    int value;
    cin >> value;

    p.setA(value);

    if (checkPrime(p))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}