#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;

        ans ^= x;
        ans ^= i;
    }

    ans ^= n;
    cout << ans;
    return 0;
}