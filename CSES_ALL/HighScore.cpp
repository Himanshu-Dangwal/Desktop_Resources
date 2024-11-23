#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
#define pii pair<ll,ll>
#define f first
#define s second
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
// find_by_order() 
// order_of_key()

const int maxN = 2600;
int n, m;
vector<pii> adj2[maxN];
vector<ll> adj[maxN];
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<int> par(maxN);
vector<ll> indegree(maxN, 0);
queue<ll> q;
vector<pair<ll, pii>> edges;
vector<bool> vis(maxN, false);

void dfs(int u) {
    vis[u] = true;

    for (auto child : adj[u]) {
        if (!vis[child]) {
            dfs(child);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0;i < m;i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        // indegree[b]++;
        edges.push_back({ a,{b,c} });
        adj[b].push_back(a);
    }

    dfs(n - 1);
    // for (int i = 0;i < n;i++) {
    //     if (indegree[i] == 0) {
    //         q.push(i);
    //     }
    // }

    // while (!q.empty()) {
    //     auto curr = q.front();
    //     q.pop();

    //     for (auto ele : adj[curr]) {
    //         indegree[ele]--;
    //         if (indegree[ele] == 0) {
    //             q.push(ele);
    //         }
    //     }
    // }



    vector<ll> dist(n, -1e18);

    //Relax all edges (m-1) times
    dist[0] = 0LL;
    for (int i = 0;i < n - 1;i++) {
        for (auto edge : edges) {
            ll u = edge.f, v = edge.s.f, w = edge.s.s;
            if (dist[u] != -1e18 && (dist[u] + w > dist[v])) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // ll currFinalDist = dist[n - 1];
    // cout << currFinalDist << endl;
    // for (auto d : dist) {
    //     cout << d << " ";
    // }
    // cout << endl;

    vector<ll> lastDistances = dist;
    for (auto edge : edges) {
        ll u = edge.f, v = edge.s.f, w = edge.s.s;
        if (dist[u] != -1e18 && (dist[u] + w > dist[v])) {
            dist[v] = dist[u] + w;
        }
    }
    // for (auto d : dist) {
    //     cout << d << " ";
    // }
    // cout << endl;
    vector<ll> changed;
    for (ll i = 0;i < n;i++) {
        if (dist[i] != lastDistances[i]) {
            changed.push_back(i);
        }
    }


    for (auto node : changed) {
        if (vis[node]) {
            cout << "-1";
            return 0;
        }
    }


    // if (dist[n - 1] > currFinalDist) {
    //     cout << "-1";
    //     return 0;
    // }

    cout << dist[n - 1];
    return 0;
}




