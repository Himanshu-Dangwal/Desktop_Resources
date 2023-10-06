#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> &nums)
{
    int n = nums.size();
    int ans = n;

    set<int> st;
    for (int x : nums)
        st.insert(x);

    vector<int> sortedArr;

    for (auto x : st)
    {
        sortedArr.push_back(x);
    }

    for (int i = 0; i < sortedArr.size(); i++)
    {
        int curr = sortedArr[i];
        int last = curr + n - 1;

        int idx = upper_bound(sortedArr.begin(), sortedArr.end(), last) - sortedArr.begin();

        ans = min(ans, n - (idx - i));
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

    cout << minOperations(nums);
}