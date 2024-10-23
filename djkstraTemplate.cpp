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

int main()
{
    int n;
    cin >> n;
    vector<vector<PII>> adj(n);

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }

    vector<ll> distance = djkstra(adj, 0, n);
    for (auto it : distance)
        cout << it << " ";

    return 0;
}