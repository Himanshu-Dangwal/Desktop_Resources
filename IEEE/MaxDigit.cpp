#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

string max_number;
int K;

void dfs(string& current, int depth, set<string>& visited) {
    if (depth == K) {  // Stop if reached maximum allowed swaps
        max_number = max(max_number, current);
        return;
    }

    max_number = max(max_number, current);

    for (int i = 0; i < current.size(); i++) {
        for (int j = i + 1; j < current.size(); j++) {
            if (i == 0 && current[j] == '0') continue;  // Avoid leading zero

            swap(current[i], current[j]);

            // Only proceed if the configuration hasn't been visited in this depth
            if (visited.find(current + to_string(depth)) == visited.end()) {
                visited.insert(current + to_string(depth));
                dfs(current, depth + 1, visited);
            }

            swap(current[i], current[j]);  // Backtrack
        }
    }
}

int main() {
    long long N;
    cin >> N >> K;

    string digits = to_string(N);
    max_number = digits;

    set<string> visited;
    dfs(digits, 0, visited);

    cout << max_number << endl;
    return 0;
}
