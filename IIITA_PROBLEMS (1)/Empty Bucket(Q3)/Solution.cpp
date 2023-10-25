#include <bits/stdc++.h>
using namespace std;
#define int __int128
int32_t main()
{
    int64_t t;
    cin >> t;
    while (t--)
    {
        int64_t a, b;
        cin >> a >> b;
        int beg = 1, end = 4 * 1e9, ans = 0;
        int temp = 4 * a * b;
        while (beg <= end)
        {
            int mid = (beg + end) / 2;
            int temp1 = (mid + 1) * (mid * mid + mid + 2);
            if (temp1 >= temp)
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                beg = mid + 1;
            }
        }
        cout << (int64_t)ans << endl;
    }
}