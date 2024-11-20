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


int main()
{
    int n;
    cin >> n;

    vector<pair<ll, pii>> arr;
    for (int i = 0;i < n;i++) {
        ll s, e, p;
        cin >> s >> e >> p;
        arr.push_back({ e,{s,p} });
    }
    sort(arr.begin(), arr.end());
    // for (int i = 0;i < n;i++) {
    //     cout << arr[i].f << " ";
    // }
    // cout << endl;
    // pair<ll, pii> curr = { 6,{INT_MAX,INT_MAX} };
    // auto comp = [](const pair<ll, pii>& a, const pair<ll, pii>& b) {
    //     return a.first < b.first;
    //     };
    // int idx = lower_bound(arr.begin(), arr.end(), curr, comp) - arr.begin();
    // cout << idx << endl;

    vector<ll> dp(n);
    dp[0] = arr[0].s.s;

    for (int i = 1;i < n;i++) {
        ll exclude = dp[i - 1];
        pair<ll, pii> curr = { arr[i].s.f,{INT_MAX,INT_MAX} };
        ll include = arr[i].s.s;

        auto comp = [](const pair<ll, pii>& a, const pair<ll, pii>& b) {
            return a.first < b.first;
            };

        int idx = lower_bound(arr.begin(), arr.end(), curr, comp) - arr.begin();
        idx -= 1;
        // cout << arr[i].s.f << " " << idx << endl;
        if (idx >= 0) {
            include += dp[idx];
        }
        // cout << include << " " << exclude << endl;
        // cout << include << " " << exclude << endl;
        dp[i] = max(include, exclude);
        // ll maxi = 0;
        // for (int j = i - 1;j >= 0;j--) {
        //     if (arr[j].f < arr[i].s.f) {
        //         maxi = max(maxi, dp[j]);
        //         break;
        //     }
        // }

        // include += maxi;
        // dp[i] = max(include, exclude);

    }

    cout << dp[n - 1];
    return 0;
}


// 1 3 5 6 6 7 9
// 6