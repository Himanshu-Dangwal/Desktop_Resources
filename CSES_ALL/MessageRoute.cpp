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

class DSU {
    vector<int> parent, rank, n;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0;i < n;i++) {
            parent[i] = i;
        }
    }

    int getParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = getParent(parent[node]);
    }

    void Union(int u, int v) {
        int ulpu = getParent(u);
        int ulpv = getParent(v);

        if (rank[ulpu] == rank[ulpv]) {
            parent[ulpu] = ulpv;
            rank[ulpv]++;
        }
        else if (rank[ulpu] < rank[ulpv]) {
            parent[ulpu] = ulpv;
        }
        else {
            parent[ulpv] = ulpu;
        }
    }

    void minEdges() {
        int cnt = 0;
        vector<int> ans;
        for (int i = 0;i < parent.size();i++) {
            if (parent[i] == i) {
                ans.push_back(i + 1);
                cnt++;
            }
        }

        cout << cnt - 1 << endl;
        if (cnt - 1 > 0) {
            for (int i = 1;i < ans.size();i++) {
                cout << ans[i] << " " << ans[i - 1] << endl;
            }
        }
    }
};


int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> adj(n);
    for (int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;

        a--, b--;
        adj[a].push_back({ b,1 });
        adj[b].push_back({ a,1 });
    }

    vector<int> distance(n, INT_MAX);
    vector<int> parent(n, -1);
    parent[0] = -1;
    distance[0] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    //Distance,vertex
    pq.push({ 0,0 });

    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        int currDist = curr.f;
        int currNode = curr.s;

        // cout << currNode << " " << currDist << endl;

        if (currDist != distance[currNode]) {
            continue;
        }


        for (auto child : adj[currNode]) {
            if (currDist + child.s < distance[child.f]) {
                distance[child.f] = currDist + child.s;
                parent[child.f] = currNode;
                pq.push({ distance[child.f],child.f });
            }
        }
    }

    // for (int i = 0;i < n;i++) {
    //     cout << parent[i] << " ";
    // }
    // cout << endl;

    if (distance[n - 1] == INT_MAX) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    cout << distance[n - 1] + 1 << endl;


    vector<int> path;

    int currNode = n - 1;
    while (parent[currNode] != -1) {
        path.push_back(currNode);
        currNode = parent[currNode];
    }
    path.push_back(0);

    reverse(path.begin(), path.end());
    for (int node : path) {
        cout << node + 1 << " ";
    }
    return 0;
}
