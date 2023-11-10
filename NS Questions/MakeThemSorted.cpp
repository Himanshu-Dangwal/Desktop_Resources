#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
    lli t;
    cin >> t;
    while (t--)
    {
        lli n;
        cin >> n;
        lli arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int mini = INT_MAX, maxi = INT_MIN;
        int mini_idx = 0, maxi_idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < mini)
            {
                mini = arr[i];
                mini_idx = i;
            }
            if (arr[i] > maxi)
            {
                maxi = arr[i];
                maxi_idx = i;
            }
        }
        if (mini_idx > maxi_idx)
            cout << ((n - 1) - maxi_idx + mini_idx) - 1 << endl;
        else
            cout << ((n - 1) - maxi_idx + mini_idx) << endl;
    }
}
