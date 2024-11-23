#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
#define pii pair<ll,ll>
#define f first
#define s second

const int maxN = 2600;
vector<pii> adj[maxN];
ll n, m;
ll dist[maxN], vis[maxN], par[maxN];

int main() {
    cin >> n >> m;

    for (int i = 0;i < m;i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({ b,c });
    }

    for (int i = 0;i <= n - 1;i++) {
        for (int j = 0;j < n;j++) {
            for (auto child : adj[j]) {
                auto childNode = child.f, edw = child.s;
                if (dist[j] + edw < dist[childNode]) {
                    dist[childNode] = dist[j] + edw;
                    par[childNode] = j;

                    if (i == n - 1) {
                        cout << "YES" << endl;
                        while (!vis[j]) {
                            vis[j] = 1;
                            j = par[j];
                        }

                        vector<ll> ans;
                        ans.push_back(j);
                        ll u = j;
                        u = par[u];
                        while (u ^ j) {
                            ans.push_back(u);
                            u = par[u];
                        }

                        ans.push_back(u);

                        reverse(ans.begin(), ans.end());
                        for (auto it : ans) {
                            cout << it + 1 << " ";
                        }
                        return 0;
                    }
                }
            }
        }
    }
    cout << "NO";
    return 0;
}