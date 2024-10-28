#include<bits/stdc++.h>
using namespace std;

double dp[41][41][41][41]; // Memoization table

double calculate_probability(int R1, int B1, int R2, int B2) {
    if (dp[R1][B1][R2][B2] >= 0) {
        return dp[R1][B1][R2][B2];
    }

    if (R1 == 0 && B1 == 0) return dp[R1][B1][R2][B2] = 0.0;
    if (R2 == 0 && B2 == 0) return dp[R1][B1][R2][B2] = 1.0;

    double total_prob = 0.0;
    int total_outcomes = 0;

    if (R1 > 0) {
        if (R2 > 0) {
            total_prob += calculate_probability(R1 - 1, B1, R2 - 1, B2); // Alice loses a red
            total_outcomes++;
        }
        if (B2 > 0) {
            total_prob += calculate_probability(R1 - 1, B1, R2, B2 - 1); // Alice loses a red
            total_outcomes++;
        }
    }

    // Alice chooses blue
    if (B1 > 0) {
        // Bob guesses red
        if (R2 > 0) {
            total_prob += calculate_probability(R1, B1 - 1, R2 - 1, B2); // Alice loses a blue
            total_outcomes++;
        }
        // Bob guesses blue
        if (B2 > 0) {
            total_prob += calculate_probability(R1, B1 - 1, R2, B2 - 1); // Alice loses a blue
            total_outcomes++;
        }
    }

    // Average the probabilities
    if (total_outcomes > 0) {
        return dp[R1][B1][R2][B2] = total_prob / total_outcomes;
    }

    return dp[R1][B1][R2][B2] = 0.0; // No valid moves
}

int main() {
    int R1, B1, R2, B2;
    cin >> R1 >> B1 >> R2 >> B2;

    // Initialize the memoization table with -1
    for (int i = 0; i <= 40; i++) {
        for (int j = 0; j <= 40; j++) {
            for (int k = 0; k <= 40; k++) {
                for (int l = 0; l <= 40; l++) {
                    dp[i][j][k][l] = -1.0;
                }
            }
        }
    }

    double result = calculate_probability(R1, B1, R2, B2);
    cout << fixed << setprecision(6) << result << endl;

    return 0;
}
