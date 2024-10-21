#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main()
{
    int n;
    cin >> n;

    vector<ll> arr(n);
    for (int i = 0; i < n; cin >> arr[i++])
        ;

    ll ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            ans += arr[i - 1] - arr[i];
            arr[i] = arr[i - 1];
        }
    }

    cout << ans;
    return 0;
}