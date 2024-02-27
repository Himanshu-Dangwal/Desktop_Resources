#include <bits/stdc++.h>
using namespace std;

int getSum(int a, int b)
{
    int x = abs(a);
    int y = abs(b);

    if (x < y)
    {
        return getSum(b, a);
    }

    int sign = a > 0 ? 1 : -1;

    if (a * b >= 0)
    {

        while (y != 0)
        {
            int answer = x ^ y;
            int carry = (x & y) << 1;

            x = answer;
            y = carry;
        }
    }
    else
    {

        while (y != 0)
        {
            int answer = x ^ y;
            int carry = ((~x) & y) << 1;

            x = answer;
            y = carry;
        }
    }

    return x * sign;
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << getSum(a, b);
}