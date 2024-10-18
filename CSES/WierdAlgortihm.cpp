#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main()
{
    long long n;
    cin >> n;
    cout << n;

    if (n == 1)
    {
        return 0;
    }
    else
    {
        cout << " ";
    }
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
            cout << n << " ";
        }
        else
        {
            n *= 3;
            n++;
            cout << n << " ";
        }
    }

    return 0;
}