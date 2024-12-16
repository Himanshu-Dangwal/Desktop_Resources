#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    vector<int> prefix_sum(n + 1, 0);

    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + (s[i] - '0');
    }

    int max_len = 0;

    for (int len = 2; len <= n; len += 2) {
        for (int i = 0; i + len <= n; i++) {
            int mid = i + len / 2;
            int left_sum = prefix_sum[mid] - prefix_sum[i];
            int right_sum = prefix_sum[i + len] - prefix_sum[mid];

            if (left_sum == right_sum) {
                max_len = max(max_len, len);
            }
        }
    }

    cout << max_len << endl;

    return 0;
}
