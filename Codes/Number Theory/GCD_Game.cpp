#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

int GCD(int a, int b)
{
    if (a == 0)
    {
        return b;
    }

    return GCD(b, a % b);
}

int main()
{
    // Your code here
    int a, b, n;
    cin >> a >> b >> n;
    bool flag = true;
    while (true)
    {
        int curr = flag ? GCD(a, n) : GCD(b, n);
        if (curr <= n)
        {
            n -= curr;
        }
        else
        {
            break;
        }

        flag = !flag;
    }

    if (flag)
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
    return 0;
}
