#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int product(int a, int b)
{
    if (b == 0)
        return 0;
    return a + product(a, b - 1);
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << product(a, b);
    return 0;
}