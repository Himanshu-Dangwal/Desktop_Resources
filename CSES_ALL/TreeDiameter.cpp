#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
#define f first
#define s second 
#define pii pair<ll,ll>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
// find_by_order() 
// order_of_key()

const int maxN = 2e5 + 7;
ll n;
vector<ll> adj[maxN];
unordered_map<ll, pii> mp;
pii dfs(ll u, ll par) {

    if (mp.find(u) != mp.end()) {
        return mp[u];
    }

    ll leaf = 1;
    for (auto child : adj[u]) {
        if (child != par) {
            leaf = 0;
            dfs(child, u);
        }
    }

    if (leaf) return { 1,0 };

    ll overallMaxiDiameter = 0;
    ll maxiHeight = 0, secondMaxiHeight = 0;
    for (ll child : adj[u]) {
        if (child != par) {
            pii childVal = dfs(child, u);
            ll currH = childVal.f, currD = childVal.s;
            overallMaxiDiameter = max(overallMaxiDiameter, currD);

            if (currH > maxiHeight) {
                secondMaxiHeight = maxiHeight;
                maxiHeight = currH;
            }
            else if (currH > secondMaxiHeight) {
                secondMaxiHeight = currH;
            }
        }
    }

    overallMaxiDiameter = max(overallMaxiDiameter, maxiHeight + secondMaxiHeight);

    return mp[u] = { maxiHeight + 1,overallMaxiDiameter };
}


int main()
{
    cin >> n;

    for (ll i = 0;i < n - 1;i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    pii ans = dfs(1, -1);
    cout << ans.s;
    return 0;
}







// 1 2 3 4

// 1 - 2 > a b
// 1 - 3 > c d
// 1 - 4 > e f
// 2 - 3 > g h
// 2 - 4 > i j
// 3 - 4 > k l



// (a + c + e) - (b + d + f) = 3
// (b + g + i) - (a + h + j) = -4
// (d + h + k) - (c + g + l) = 5


// (f + j + l) - (e + i + k) = ?
