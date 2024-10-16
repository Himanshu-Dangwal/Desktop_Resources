#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

class DSU
{
    vector<int> rank, parent, size;

public:
    DSU(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int getParent(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }

        return parent[node] = getParent(parent[node]);
    }

    void UnionByRank(int u, int v)
    {
        int ulp_u = getParent(u);
        int ulp_v = getParent(v);

        if (ulp_u == ulp_v)
        {
            return;
        }

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }

    void UnionBySize(int u, int v)
    {
        int ulp_u = getParent(u);
        int ulp_v = getParent(v);

        if (ulp_u == ulp_v)
        {
            return;
        }

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

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