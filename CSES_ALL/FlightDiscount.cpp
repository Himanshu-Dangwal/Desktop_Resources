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
const int maxN = 2e5;
ll n, m;
vector<vector<pii>> adj(maxN), adj2(maxN);
priority_queue<pii, vector<pii>, greater<pii>> pq;

void djkstra(int u, vector<ll>& dist, vector<vector<pii>>& adj) {
    dist[u] = 0;
    pq.push({ 0,u });
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        ll currWeight = curr.f, currNode = curr.s;

        if (dist[currNode] < currWeight) continue;

        for (auto child : adj[currNode]) {
            ll childNode = child.f, edW = child.s;
            if ((currWeight + edW) < dist[childNode]) {
                dist[childNode] = currWeight + edW;
                pq.push({ dist[childNode],childNode });
            }
        }
    }

}

int main() {
    cin >> n >> m;
    for (int i = 0;i < m;i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({ b,c });
        adj2[b].push_back({ a,c });
    }
    vector<ll> dist1(n, 1e18), dist2(n, 1e18);
    djkstra(0, dist1, adj);
    djkstra(n - 1, dist2, adj2);
    ll ans = 1e18;
    for (ll i = 0;i < n;i++) {
        for (auto child : adj[i]) {
            ans = min(ans, dist1[i] + dist2[child.f] + (child.s / 2));
        }
    }

    cout << ans;

    return 0;
}




