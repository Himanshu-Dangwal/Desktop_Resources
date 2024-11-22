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

    vector<int> adj[n];
    vector<int> team(n, -1);
    for (int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<pii> q;

    q.push({ 0,0 });
    team[0] = 1;

    vector<bool> vis(n, false);

    for (int i = 0;i < n;i++) {
        if (!vis[i]) {
            vis[i] = true;
            queue<pii> q;
            q.push({ i,0 });
            team[i] = 0;

            while (!q.empty()) {
                auto curr = q.front();
                q.pop();

                int currNode = curr.f;
                int currTeam = curr.s;

                for (auto child : adj[currNode]) {
                    if (team[child] == -1) {
                        team[child] = currTeam ^ 1;
                        q.push({ child,team[child] });
                        vis[child] = true;
                    }
                    else {
                        if (team[child] == currTeam) {
                            cout << "IMPOSSIBLE";
                            return 0;
                        }
                    }
                }
            }
        }
    }



    for (int i = 0;i < n;i++) {
        cout << team[i] + 1 << " ";
    }

    return 0;
}
