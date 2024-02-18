#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long> arr(n);

    for (int i = 0; i < n; cin >> arr[i++])
        ;

    for (int i = 1; i < n; i++)
    {
        arr[i] += arr[i - 1];
    }

    int q;
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        long ans;
        if (l == 0)
        {
            ans = arr[r - 1];
        }
        else
        {
            ans = arr[r - 1] - arr[l - 1];
        }

        cout << ans << endl;
    }
}