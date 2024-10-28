#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> rank, parent;

public:
    DSU(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int getParent(int node) {
        if (parent[node] != node) {
            parent[node] = getParent(parent[node]); // Path compression
        }
        return parent[node];
    }

    void Union(int u, int v) {
        int pu = getParent(u);
        int pv = getParent(v);
        if (pu != pv) {
            // Union by rank
            if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
            }
            else if (rank[pu] > rank[pv]) {
                parent[pv] = pu;
            }
            else {
                parent[pu] = pv;
                rank[pv]++;
            }
        }
    }
};

bool countComponentsForLength(const string& S, int k, int target) {
    int n = S.size();
    int maxi = 0;
    for (int l = 0; l <= n - k; l++) {
        string T = S.substr(l, k);
        DSU dsu(n);

        for (int i = 0;i <= n - k;i++) {
            if (S.substr(i, k) == T) {
                for (int j = i;j < i + k - 1;j++) {
                    dsu.Union(j, j + 1);
                }
            }
        }
        int cnt = 0;
        for (int i = 0;i < n;i++) {
            if (dsu.getParent(i) == i) {
                cnt++;
            }
        }

        if (cnt == target) return true;
    }
    return false;

}

vector<int> minimumLengthForConnectedComponents(const string& S) {
    int N = S.size();
    vector<int> minLength(N + 1, INT_MAX);

    for (int i = 1; i <= N; i++) {
        int low = 1, high = N, bestLength = INT_MAX;

        while (low <= high) {
            if (countComponentsForLength(S, low, i)) {
                bestLength = min(bestLength, low);
            }

            low++;
        }

        minLength[i] = (bestLength == INT_MAX) ? 0 : bestLength;

    }

    return vector<int>(minLength.begin() + 1, minLength.end());
}

int main() {
    string S;
    cin >> S;

    vector<int> result = minimumLengthForConnectedComponents(S);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
