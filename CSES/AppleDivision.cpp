#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
ll sum;
ll diff;
void solve(int idx, vector<ll> &arr, ll currSum)
{

    if (idx == arr.size())
    {
        ll sum2 = sum - currSum;
        if (abs(currSum - sum2) < diff)
        {
            diff = abs(currSum - sum2);
        }
        return;
    }
    solve(idx + 1, arr, currSum + arr[idx]);
    solve(idx + 1, arr, currSum);
}

int main()
{
    int n;
    cin >> n;

    vector<ll> arr(n);
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    diff = sum;
    solve(0, arr, 0);
    cout << diff;
    return 0;
}