#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

bool check(ll mid, ll sum, vector<int> &arr)
{
    int n = arr.size();

    ll totalSum = sum + mid;
    double avg = (double)totalSum / (2.0 * n);

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            if (arr[i] + mid < avg)
                cnt++;
            break;
        }
        if (arr[i] < avg)
            cnt++;
    }

    return cnt > (n / 2);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; cin >> arr[i++])
            ;
        if (n == 1 || n == 2)
        {
            cout << "-1" << endl;
            continue;
        }
        sort(arr.begin(), arr.end());

        ll sum = 0;
        for (int x : arr)
            sum += x;
        ll low = 0, high = 1e18;
        ll ans = -1;
        while (low <= high)
        {
            ll mid = (low + high) / 2;
            if (check(mid, sum, arr))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}