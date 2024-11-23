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
int n, m;
vector<pii> adj[maxN];
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<int> par(maxN);


int main() {
    cin >> n >> m;
    for (int i = 0;i < m;i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({ b,c });
    }
    vector<ll> dist(n, 1e18);
    // memset(dist, 1e18, sizeof(dist));
    dist[0] = 0;
    pq.push({ 0,0 });

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

    for (int i = 0;i < n;i++) {
        cout << dist[i] << " ";
    }
    return 0;
}




