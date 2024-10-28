#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum of the maximum pair sums using sorted array
long long calculateMinMaxPairSum(vector<int>& arr) {
    int n = arr.size();
    // Sort the array
    sort(arr.begin(), arr.end());

    int minMaxSum = INT_MAX;

    // Create pairs from the sorted array
    for (int i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            // Calculate the maximum sum of this pairing
            int maxSum = arr[i] + arr[i + 1];
            minMaxSum = min(minMaxSum, maxSum);
        }
    }

    return minMaxSum;
}

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> queries(Q);
    for (int i = 0; i < Q; i++) {
        cin >> queries[i];
    }

    vector<long long> results(Q);

    // For each query
    for (int qi = 0; qi < Q; qi++) {
        int x = queries[qi];
        long long totalSum = 0;

        // Sliding window to generate all possible subarrays
        for (int l = 0; l < N; l++) {
            vector<int> temp;
            for (int r = l; r < N; r++) {
                temp.push_back(A[r]);

                // Calculate the optimal cost only for even-length subarrays
                if ((r - l + 1) % 2 == 0) {
                    long long optimalCost = calculateMinMaxPairSum(temp);

                    if (optimalCost <= x) {
                        totalSum += (A[r] - A[l]); // Sum of the differences
                    }
                }
            }
        }

        results[qi] = totalSum; // Store result for current query
    }

    // Output results for each query
    for (const auto& result : results) {
        cout << result << endl;
    }

    return 0;
}
