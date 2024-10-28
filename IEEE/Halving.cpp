#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    int N;
    cin >> N;

    vector<int> C(2 * N);
    for (int i = 0; i < 2 * N; i++) {
        cin >> C[i];
    }

    vector<int> R(N);
    for (int i = 0; i < N; i++) {
        cin >> R[i];
    }

    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    // Set to store readable values
    set<int> readable;
    for (int x : C) {
        if (x != -1) {
            readable.insert(x);
        }
    }

    // Set to track the needed values from B
    set<int> needed;
    for (int b : B) {
        needed.insert(b);
    }

    long long count = 1; // This will store the count of valid assignments

    // We will need to check for each B[i] what can be formed from C
    for (int i = 0; i < N; i++) {
        int required = B[i];
        int a1 = C[2 * i], a2 = C[2 * i + 1];

        bool valid = false; // Track if we can form the required value
        int availableChoices = 0;

        if (R[i] == 0) { // Min case
            if (a1 == -1 && a2 == -1) {
                // Both are unknown, we can choose any two numbers
                availableChoices = 2; // Two positions available
            }
            else if (a1 == -1 || a2 == -1) {
                // One is known, one is unknown
                int knownValue = (a1 != -1) ? a1 : a2;
                if (knownValue == required) {
                    valid = true; // It can form the required min
                }
            }
            else {
                // Both are known
                if (min(a1, a2) == required) {
                    valid = true; // It can form the required min
                }
            }
        }
        else { // Max case
            if (a1 == -1 && a2 == -1) {
                // Both are unknown, we can choose any two numbers
                availableChoices = 2; // Two positions available
            }
            else if (a1 == -1 || a2 == -1) {
                // One is known, one is unknown
                int knownValue = (a1 != -1) ? a1 : a2;
                if (knownValue == required) {
                    valid = true; // It can form the required max
                }
            }
            else {
                // Both are known
                if (max(a1, a2) == required) {
                    valid = true; // It can form the required max
                }
            }
        }

        if (!valid && availableChoices == 0) {
            // No choices available means inconsistency
            cout << 0 << endl;
            return 0;
        }

        // If valid, count the possible ways
        if (availableChoices == 2) {
            // Both are -1, count valid pairs
            int totalAvailable = 0;
            for (int num = 1; num <= 2 * N; num++) {
                if (needed.find(num) == needed.end() && readable.find(num) == readable.end()) {
                    totalAvailable++;
                }
            }
            // Choose 2 distinct from the available numbers
            count = (count * totalAvailable * (totalAvailable - 1) / 2) % MOD;
        }
        else if (availableChoices == 1) {
            // One is -1, count valid number
            int totalAvailable = 0;
            for (int num = 1; num <= 2 * N; num++) {
                if (needed.find(num) == needed.end() && readable.find(num) == readable.end()) {
                    totalAvailable++;
                }
            }
            count = (count * totalAvailable) % MOD;
        }
    }

    cout << count << endl;
    return 0;
}
