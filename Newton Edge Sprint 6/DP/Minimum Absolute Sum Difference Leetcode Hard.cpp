#include <bits/stdc++.h>
using namespace std;

int minimumDifference(vector<int> &nums)
{

    int n = nums.size();
    int N = n / 2;

    vector<vector<int>> left(N + 1);
    vector<vector<int>> right(N + 1);

    for (int bitmask = 0; bitmask < (1 << N); bitmask++)
    {
        int no_of_set_bits = 0;
        int mask = bitmask;
        int sum = 0;
        int idx = 0;

        while (mask > 0)
        {
            if (mask & 1)
            {
                sum += nums[idx];
                no_of_set_bits++;
            }
            idx++;
            mask = mask >> 1;
        }

        left[no_of_set_bits].push_back(sum);
    }

    for (int bitmask = 0; bitmask < (1 << N); bitmask++)
    {
        int no_of_set_bits = 0;
        int mask = bitmask;
        int sum = 0;
        int idx = 0;

        while (mask > 0)
        {
            if (mask & 1)
            {
                sum += nums[N + idx];
                no_of_set_bits++;
            }
            idx++;
            mask = mask >> 1;
        }

        right[no_of_set_bits].push_back(sum);
    }

    int sum = accumulate(nums.begin(), nums.end(), 0);
    int ans = INT_MAX;

    // a+b = sum/2:: (target)

    for (int k = 0; k <= N; k++)
    {

        vector<int> v2 = right[N - k];
        sort(v2.begin(), v2.end());

        for (int &a : left[k])
        {
            int b = (sum - 2 * a) / 2;
            auto idx = lower_bound(v2.begin(), v2.end(), b);

            if (idx != v2.end())
            {
                b = *idx;
                ans = min(ans, abs(sum - 2 * (a + b)));
            }
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    n *= 2;
    vector<int> arr(n);

    for (int i = 0; i < n; cin >> arr[i++])
        ;

    cout << minimumDifference(arr);
}