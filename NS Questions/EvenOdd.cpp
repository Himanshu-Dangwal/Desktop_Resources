#include <bits/stdc++.h>
using namespace std;

vector<int> arrangeCharacters(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);
    int i = 0, j = n - 1;
    for (int x : nums)
    {
        if (x % 2)
        {
            ans[j] = x;
            j--;
        }
        else
        {
            ans[i] = x;
            i++;
        }
    }

    return ans;
}

vector<int> sortArrayByParity(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);
    int i = 0, j = n - 1;
    for (int x : nums)
    {
        if (x % 2)
        {
            ans[j] = x;
            j--;
        }
        else
        {
            ans[i] = x;
            i++;
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; cin >> nums[i++])
        ;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] % 2 == 0)
            cnt++;
    }
    vector<int> ans1 = sortArrayByParity(nums);
    vector<int> ans = arrangeCharacters(nums);

    for (int i = 0; i < cnt; i++)
    {
        if (ans[i] != ans1[i])
        {
            cout << "false";
            return 0;
        }
    }

    cout << "true";
    return 0;
}