#include <bits/stdc++.h>
#define int long long
using namespace std;
#define nl '\n'

signed main()
{

    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int minn = INT_MAX, ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (minn < a[i])
        {
            int cnt = 0;
            while (a[i] > minn)
            {
                a[i] = (a[i] >> 1);
                cnt++;
            }
            ans = max(ans, cnt);
        }
        minn = min(minn, a[i]);
    }
    cout << ans;
}