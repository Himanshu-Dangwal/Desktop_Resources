#include<bits/stdc++.h>
using namespace std;

const int maxN = 200005;
int n, s[maxN];
vector<int> adj[maxN];

void dfs(int u = 0, int par = -1) {
    s[u] += 1;
    for (int v : adj[u]) {
        dfs(v, u);
        s[u] += s[v];
    }
}

int main() {
    cin >> n;
    for (int i = 1;i < n;i++) {
        int j;
        cin >> j;

        j--;
        adj[j].push_back(i);
    }

    dfs();
    for (int i = 0;i < n;i++) {
        cout << s[i] - 1 << " ";
    }
}