#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
#define pii pair<ll,ll>
#define f first
#define s second

const int maxN = 2e5;
vector<pii> adj[maxN];
ll n, m, k;
priority_queue<pii, vector<pii>, greater<pii>> pq;


int main() {
    cin >> n >> m >> k;
    for (int i = 0;i < m;i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({ b,c });
    }
    vector<vector<ll>> dist(n, vector<ll>(k, 1e18));
    dist[0][0] = 0LL;
    pq.push({ 0,0 });

    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        ll currNode = curr.s, currWeight = curr.f;

        if (dist[currNode][k - 1] < currWeight) continue;

        for (auto child : adj[currNode]) {
            ll childNode = child.f, edW = child.s;

            if (currWeight + edW < dist[childNode][k - 1]) {
                dist[childNode][k - 1] = currWeight + edW;
                pq.push({ dist[childNode][k - 1],childNode });
                sort(dist[childNode].begin(), dist[childNode].end());
            }
        }
    }

    for (int i = 0;i < k;i++) {
        cout << dist[n - 1][i] << " ";
    }
    return 0;
}