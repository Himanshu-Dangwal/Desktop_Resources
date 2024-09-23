#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

vector<int> kahns(int v, vector<vector<int>> &adj)
{

    vector<int> indegree(v, 0);

    for (int i = 0; i < v; i++)
    {
        for (auto dest : adj[i])
        {
            indegree[dest]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (!indegree[i])
            q.push(i);
    }
    vector<int> ans;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        ans.push_back(curr);

        for (auto child : adj[curr])
        {
            indegree[child]--;
            if (!indegree[child])
                q.push(child);
        }
    }

    return ans;
}

void solve()
{

    int n, e;
    cin >> n >> e;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
    }

    vector<int> topo = kahns(n, adj);
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