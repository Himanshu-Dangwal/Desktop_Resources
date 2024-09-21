#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int ans = 0;
        int curr = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= k)
            {
                curr += arr[i];
            }
            else if (arr[i] == 0)
            {
                if (curr > 0)
                {
                    curr -= 1;
                    ans++;
                }
            }
            else
            {
            }
        }
        cout << ans << endl;
    }
    return 0;
}