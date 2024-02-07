#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; cin >> arr[i++])
        ;

    int k;
    cin >> k;

    vector<int> prefix(n, 0);
    prefix[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        prefix[i] = arr[i] + prefix[i - 1];
    }

    vector<int> suffix(n, 0);
    suffix[n - 1] = arr[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = arr[i] + suffix[i + 1];
    }

    int ans = max(prefix[k - 1], suffix[n - k]);
    cout << ans;
}