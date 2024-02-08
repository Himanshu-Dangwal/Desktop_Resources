#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " " << n - i;
            return;
        }
    }
    cout << "-1";
    return;
}

int main()
{
    int l, r;
    cin >> l >> r;

    if (r < 4)
    {
        cout << "-1";
        return 0;
    }

    if (l != r)
    {
        cout << "2 " << (r - (r % 2) - 2);
    }
    else
    {
        if (l % 2 == 0)
        {
            cout << "2 " << (l - 2);
        }
        else
        {
            solve(l);
        }
    }
    return 0;
}