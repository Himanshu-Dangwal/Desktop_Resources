#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main()
{
    int a, b;
    cin >> a >> b;
    int sum = 0;
    for (int i = 1; i <= b; i++)
    {
        sum += a;
    }
    cout << sum;
    return 0;
}