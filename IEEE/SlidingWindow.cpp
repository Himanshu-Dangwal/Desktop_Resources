#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum pair sum in a given set of pairs
int maxPairSum(const vector<pair<int, int>>& pairs) {
    int maxSum = INT_MIN;
    for (const auto& p : pairs) {
        maxSum = max(maxSum, p.first + p.second);
    }
    return maxSum;
}

// Memoization table for optimal costs
unordered_map<string, int> memo;

// Recursive function to find the minimum of the maximum pair sums across all pairings
int findMinOfMaxPairSum(const vector<int>& arr, vector<bool>& used, vector<pair<int, int>>& pairs) {
    int n = arr.size();

    // Base case: if all elements are paired
    if (pairs.size() * 2 == n) {
        // Calculate the maximum pair sum for this arrangement
        return maxPairSum(pairs);
    }

    string key = "";  // Unique key for memoization
    for (bool u : used) {
        key += (u ? '1' : '0');
    }

    // Check if result is already computed
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    int minMaxSum = INT_MAX;  // Initialize to maximum possible value

    // Try to pair the first unpaired element with every other unpaired element
    for (int i = 0; i < n; i++) {
        if (!used[i]) {  // Find the first unused element
            used[i] = true;

            for (int j = i + 1; j < n; j++) {
                if (!used[j]) {
                    used[j] = true;
                    pairs.push_back({ arr[i], arr[j] });

                    // Recurse to find other pairings
                    int currentMaxSum = findMinOfMaxPairSum(arr, used, pairs);
                    minMaxSum = min(minMaxSum, currentMaxSum);

                    // Backtrack
                    pairs.pop_back();
                    used[j] = false;
                }
            }

            // Recurse with the current element left unpaired
            minMaxSum = min(minMaxSum, findMinOfMaxPairSum(arr, used, pairs));

            used[i] = false;
            break;  // To avoid redundant cases (symmetry)
        }
    }

    // Store the result in memoization table
    memo[key] = minMaxSum;
    return minMaxSum;
}

// Function to calculate the optimal cost for a given array
long long calculateOptimalCost(const vector<int>& arr) {
    vector<pair<int, int>> pairs;
    vector<bool> used(arr.size(), false);
    memo.clear();  // Clear the memoization table for new calculations

    return findMinOfMaxPairSum(arr, used, pairs);
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

    // Precompute optimal costs for all possible subarrays
    vector<vector<long long>> optimalCosts(N, vector<long long>(N, LLONG_MAX));
    for (int l = 0; l < N; l++) {
        for (int r = l + 1; r < N; r++) {
            vector<int> temp(A.begin() + l, A.begin() + r + 1); // Subarray A[l..r]
            optimalCosts[l][r] = calculateOptimalCost(temp);
        }
    }

    // For each query
    for (int qi = 0; qi < Q; qi++) {
        int x = queries[qi];
        long long totalSum = 0;

        // Check precomputed optimal costs
        for (int l = 0; l < N; l++) {
            for (int r = l + 1; r < N; r++) {
                if (optimalCosts[l][r] <= x) {
                    totalSum += (A[r] - A[l]); // Sum of the differences
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


//Clear