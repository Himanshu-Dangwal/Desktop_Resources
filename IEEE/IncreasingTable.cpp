// #include <iostream>
// #include <vector>
// #include <set>

// using namespace std;

// const int MOD = 998244353;

// int main() {
//     int N;
//     cin >> N;

//     // Read set A
//     int X;
//     cin >> X;
//     set<int> A;
//     for (int i = 0; i < X; ++i) {
//         int num;
//         cin >> num;
//         A.insert(num);
//     }

//     // Read set B
//     int Y;
//     cin >> Y;
//     set<int> B;
//     for (int i = 0; i < Y; ++i) {
//         int num;
//         cin >> num;
//         B.insert(num);
//     }

//     // Track counts of numbers not in A or B
//     vector<int> remaining;
//     for (int i = 1; i <= 2 * N; ++i) {
//         if (A.find(i) == A.end() && B.find(i) == B.end()) {
//             remaining.push_back(i);
//         }
//     }

//     int remaining_count = remaining.size();
//     int total_count = 2 * N;

//     // DP table for combinations
//     // dp[i][j] = number of ways to fill the first i columns with j numbers in the first row
//     vector<vector<long long>> dp(N + 1, vector<long long>(N + 1, 0));
//     dp[0][0] = 1; // Base case: one way to fill 0 columns with 0 in first row

//     // Fill DP table
//     for (int col = 1; col <= N; ++col) {
//         for (int r1 = 0; r1 <= col; ++r1) {
//             int r2 = col - r1; // Remaining for second row

//             // If r1 numbers are filled in row 1
//             if (r1 > 0 && r1 <= X) {
//                 dp[col][r1] = (dp[col][r1] + dp[col - 1][r1 - 1]) % MOD;
//             }

//             // If r2 numbers are filled in row 2
//             if (r2 > 0 && r2 <= Y) {
//                 dp[col][r1] = (dp[col][r1] + dp[col - 1][r1]) % MOD;
//             }

//             // If we place a number from remaining (filling freely)
//             if (remaining_count > 0) {
//                 dp[col][r1] = (dp[col][r1] + dp[col - 1][r1]) % MOD;
//             }
//         }
//     }

//     // The result is the sum of valid ways to fill N columns
//     long long result = 0;
//     for (int r1 = 0; r1 <= N; ++r1) {
//         result = (result + dp[N][r1]) % MOD;
//     }

//     cout << result << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

// Function to compute factorial modulo MOD
vector<long long> computeFactorials(int n) {
    vector<long long> fact(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    return fact;
}

// Function to compute modular inverse using Fermat's little theorem
long long modInverse(long long a, long long mod) {
    long long result = 1;
    long long power = mod - 2;
    while (power) {
        if (power & 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        power >>= 1;
    }
    return result;
}

// Function to compute combinations nCr % mod
long long nCr(int n, int r, const vector<long long>& fact) {
    if (r > n || r < 0) return 0;
    return (fact[n] * modInverse(fact[r], MOD) % MOD * modInverse(fact[n - r], MOD) % MOD) % MOD;
}

int main() {
    int N;
    cin >> N;

    int X;
    cin >> X;
    vector<int> A(X);
    for (int i = 0; i < X; i++) {
        cin >> A[i];
    }

    int Y;
    cin >> Y;
    vector<int> B(Y);
    for (int i = 0; i < Y; i++) {
        cin >> B[i];
    }

    // Sort arrays A and B for easy processing
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Total numbers = 2 * N
    int totalNumbers = 2 * N;

    // Calculate factorials
    vector<long long> fact = computeFactorials(totalNumbers);

    // Count numbers not in A or B
    vector<bool> inA(totalNumbers + 1, false);
    vector<bool> inB(totalNumbers + 1, false);
    for (int num : A) inA[num] = true;
    for (int num : B) inB[num] = true;

    int freeCount = 0;
    for (int i = 1; i <= totalNumbers; i++) {
        if (!inA[i] && !inB[i]) {
            freeCount++;
        }
    }

    // Calculate the number of valid ways to fill the table
    long long ways = nCr(freeCount + X + Y, X, fact);

    cout << ways << endl;
    return 0;
}
