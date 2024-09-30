#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
#define PII pair<long, long>

vector<ll> djkstra(vector<vector<PII>> &adj, int src, int n)
{
    vector<ll> weight(n, 1e18);

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    weight[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        auto currWeight = pq.top().first;
        auto node = pq.top().second;
        pq.pop();

        if (currWeight != weight[node])
            continue;

        for (auto child : adj[node])
        {
            auto weightOfEdgeToChild = child.second;
            auto childNode = child.first;
            if (weight[childNode] > currWeight + weightOfEdgeToChild)
            {
                weight[childNode] = currWeight + weightOfEdgeToChild;
                pq.push({weight[childNode], childNode});
            }
        }
    }

    return weight;
}

void solve()
{
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}