#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

// Function to compute modular exponentiation
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) { // If exp is odd, multiply base with result
            result = (result * base) % mod;
        }
        exp = exp >> 1; // Divide exp by 2
        base = (base * base) % mod; // Square the base
    }
    return result;
}

// Function to calculate combinations C(n, k)
long long nCr(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || n == k) return 1;

    long long numerator = 1;
    long long denominator = 1;

    // Calculate n! / (k! * (n-k)!)
    for (int i = 0; i < k; i++) {
        numerator = (numerator * (n - i)) % MOD;
        denominator = (denominator * (i + 1)) % MOD;
    }

    // Calculate the modular inverse of the denominator
    long long denominatorInv = modPow(denominator, MOD - 2, MOD); // Fermat's Little Theorem

    return (numerator * denominatorInv) % MOD;
}

int main() {
    int N, M;
    cin >> N >> M;

    if (M == 0) {
        cout << "infinity" << endl;
        return 0;
    }

    long long validCount = 0;

    for (int i = 0; i < M; i++) {
        long long low, high;
        int K;
        cin >> low >> high >> K;

        vector<int> indices(K);
        for (int j = 0; j < K; ++j) {
            cin >> indices[j];
            indices[j]--;
        }

        vector<int> selectedNumbers;
        for (int index : indices) {
            selectedNumbers.push_back(index + 1);
        }

        sort(selectedNumbers.begin(), selectedNumbers.end());
        do {
            long long sum = accumulate(selectedNumbers.begin(), selectedNumbers.end(), 0LL);
            if (sum >= low && sum <= high) {
                validCount = (validCount + 1) % MOD;
            }
        } while (next_permutation(selectedNumbers.begin(), selectedNumbers.end()));

    }

    cout << validCount % MOD << endl;

    return 0;
}
