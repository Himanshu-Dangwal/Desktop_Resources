#include<bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 10;
int n;
vector<int> adj[maxN];
vector<int> s(maxN);

void dfs(int u, int par) {
    s[u] = 1;
    for (int v : adj[u]) {
        if (v != par) {
            dfs(v, u);
            s[u] += s[v];
        }
    }
}

int main() {
    cin >> n;

    for (int i = 2;i <= n;i++) {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }

    dfs(1, -1);
    for (int i = 1;i <= n;i++) {
        cout << s[i] - 1 << " ";
    }
}