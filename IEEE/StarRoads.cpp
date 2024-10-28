#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
// find_by_order() 
// order_of_key()

// DFS function to find a path from src to dest
bool findPath(vector<vector<int>>& adj, int src, int dest, vector<bool>& visited, vector<int>& currPath) {
    currPath.push_back(src);
    if (src == dest) return true; // Path found

    visited[src] = true;
    for (int child : adj[src]) {
        if (!visited[child]) {
            if (findPath(adj, child, dest, visited, currPath)) {
                return true;
            }
        }
    }
    // If no path is found, remove the last node from the current path
    currPath.pop_back();
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> vp; // {star value, node index}
    unordered_map<int, int> mp; // {node index, star value}

    for (int i = 0; i < n; i++) {
        int star;
        cin >> star;
        vp.push_back({ star, i });
        mp[i] = star;  // Populate the map with the star values
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; // Convert to 0-based index
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    sort(vp.begin(), vp.end()); // Sort nodes based on star values

    int ans = 1;
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (vp[j].first < vp[i].first) {
                vector<bool> visited(n, false);
                vector<int> currPath;

                // Find path from node vp[j].second to node vp[i].second
                if (findPath(adj, vp[j].second, vp[i].second, visited, currPath)) {
                    vector<int> stars;

                    // Map each node in the path to its star value
                    for (int ele : currPath) {
                        stars.push_back(mp[ele]);
                    }

                    int sz = stars.size();
                    int maxi = 1;
                    vector<int> dp(sz, 1);

                    // Calculate the longest increasing subsequence in stars
                    for (int k = 1; k < sz; k++) {
                        for (int l = 0; l < k; l++) {
                            if (stars[l] < stars[k]) {
                                dp[k] = max(dp[k], dp[l] + 1);
                                maxi = max(maxi, dp[k]);
                            }
                        }
                    }
                    ans = max(ans, maxi); // Update the global answer
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
