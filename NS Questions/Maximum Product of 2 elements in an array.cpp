#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    return (nums[n - 1] - 1) * (nums[n - 2] - 1);
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << maxProduct(arr);
}