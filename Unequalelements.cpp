#include<bits/stdc++.h>
using namespacen std;
struct DPState {
    int maxLength;
    unordered_set<int> elements;
    unordered_map<int, int> countMap;
};

int findMaxLength(vector<int>& arr, int k) {
    int n = arr.size();
    vector<DPState> dp(k + 1);

    for (int i = 0; i < n; ++i) {
        int prev = 0;
        for (int j = 0; j <= k; ++j) {
            int cur = max({ prev + 1, (dp[j].maxLength + 1) * (dp[j].elements.count(arr[i]) > 0), dp[j].countMap[arr[i]] + 1 });

            prev = dp[j].maxLength;
            dp[j].countMap[arr[i]] = cur;

            if (dp[j].maxLength < cur) {
                dp[j].maxLength = cur;
                dp[j].elements.clear();
            }

            if (cur == dp[j].maxLength) {
                dp[j].elements.insert(arr[i]);
            }
        }
    }

    return dp[k].maxLength;
}