#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(nums.begin(), nums.end());

    int i = 0;
    int j = 0;
    int ans = 0;
    while (j < nums.size())
    {
        while ((nums[i] == nums[j]))
        {
            j++;
        }

        int size = i - j + 1;
        size--;
        ans += (size * (size + 1)) / 2;
        i = j;
    }
    cout << ans;
}