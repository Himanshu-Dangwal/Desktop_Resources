#include <bits/stdc++.h>
using namespace std;

// Helper function to count adjacent swaps to convert p to target
int countSwaps(vector<int>& p, vector<int>& target) {
    int n = p.size();
    int swaps = 0;

    // Create a mapping of element to its position in the target
    unordered_map<int, int> targetIndex;
    for (int i = 0; i < n; ++i) {
        targetIndex[target[i]] = i;
    }

    // Create a visited array to keep track of visited elements
    vector<bool> visited(n, false);

    // Count swaps by detecting cycles
    for (int i = 0; i < n; ++i) {
        if (visited[i] || targetIndex[p[i]] == i) {
            continue;
        }

        int cycle_size = 0;
        int j = i;

        // Count the size of the cycle
        while (!visited[j]) {
            visited[j] = true;
            j = targetIndex[p[j]];
            cycle_size++;
        }

        if (cycle_size > 0) {
            swaps += (cycle_size - 1);
        }
    }

    return swaps;
}

// Function to generate increasing-decreasing valid permutations
bool isValidIncreasingDecreasing(const vector<int>& perm) {
    int n = perm.size();
    int mid = (n + 1) / 2;

    // Check if the first half is increasing and second half is decreasing
    for (int i = 1; i < mid; ++i) {
        if (perm[i] <= perm[i - 1]) return false;
    }
    for (int i = mid; i < n; ++i) {
        if (perm[i] >= perm[i - 1]) return false;
    }
    return true;
}

// Function to find the target permutation with the least swaps
int findBestIncreasingDecreasingPermutation(vector<int> p) {
    int n = p.size();
    vector<int> sorted_p = p;
    sort(sorted_p.begin(), sorted_p.end());

    long long min_swaps = LLONG_MAX; // To track the minimum swaps
    vector<int> best_target; // To store the best target permutation

    // Generate all permutations of the sorted array
    do {
        if (isValidIncreasingDecreasing(sorted_p)) { // Check if valid
            int swaps = countSwaps(p, sorted_p); // Count swaps needed
            if (swaps < min_swaps) {
                min_swaps = swaps; // Update minimum swaps
                best_target = sorted_p; // Update the best target
            }
        }
    } while (next_permutation(sorted_p.begin(), sorted_p.end()));

    // Output the best target and its swaps
    // if (min_swaps < LLONG_MAX) {
    //     // cout << "Best target permutation: ";
    //     for (int num : best_target) {
    //         cout << num << " ";
    //     }
    //     // cout << "\nMinimum swaps needed: " << min_swaps << endl;
    // }

    return min_swaps == LLONG_MAX ? LLONG_MAX : min_swaps;
}

int main() {
    int N;
    // cout << "Enter the size of the permutation: ";
    cin >> N;
    int M;
    cin >> M;

    vector<int> perm(N);
    for (int i = 0;i < N;i++) {
        perm[i] = i + 1;
    }
    int ans = 0;
    do {
        ans += findBestIncreasingDecreasingPermutation(perm);
        ans = ans % M;
    } while (next_permutation(perm.begin(), perm.end()));
    cout << ans;
    return 0;
}
