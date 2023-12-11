#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ans = 0;
    void solve(int i, vector<int> &arr, int target)
    {
        if (target == 0)
        {
            ans++;
            return;
        }
        if (target < 0)
            return;
        if (i == arr.size())
            return;
        solve(i + 1, arr, target);
        solve(i, arr, target - arr[i]);
    }
    int combinationSum(vector<int> &arr, int target)
    {
        solve(0, arr, target);
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Solution ans;
    int k;
    cin >> k;
    cout << ans.combinationSum(a, k) << endl;
    return 0;
}