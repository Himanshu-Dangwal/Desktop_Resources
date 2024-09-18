#include <bits/stdc++.h>
using namespace std;

int maxLightPoint(vector<int> &arr, int r)
{
    unordered_set<int> st;
    for (int x : arr)
        st.insert(x);

    int n = arr.size();
    int ans = arr[0] - r;

    int left = ans, pivot = arr[0] + r, cnt = 0, maxi = 0;
    int start = left;
    int right = arr[n - 1] + r;
    while (left < right)
    {
        if (left <= pivot)
        {
            if (st.find(left) != st.end())
            {
                cnt++;
                if (cnt > maxi)
                {
                    maxi = cnt;
                    ans = left - r;
                }
            }

            left++;
        }
        else
        {
            if (st.find(left) != st.end())
            {
                cnt++;
            }

            if (st.find(start) != st.end())
            {
                cnt--;
            }

            if (cnt > maxi)
            {
                maxi = cnt;
                ans = left - r;
            }

            left++;
            start++;
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; cin >> arr[i++])
        ;
    int radius;
    cin >> radius;
    cout << maxLightPoint(arr, radius);
}