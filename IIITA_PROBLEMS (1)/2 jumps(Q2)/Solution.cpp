#include <bits/stdc++.h>
#define int __int128
using namespace std;
set<long long> reachable;
void jump(int ind, int last, int sign, vector<__int128> &powers)
{
    // cout<<last<<' ';
    if (last > 1e18 || last < -1e18)
        return;
    reachable.insert(last);
    jump(ind + 1, last + sign * powers[ind], sign * -1, powers);
}
void solve()
{
    int64_t q;
    cin >> q;
    vector<int64_t> query(q);
    for (int64_t &it : query)
        cin >> it;
    for (int64_t it : query)
    {
        cout << (reachable.count(it) ? "YES" : "NO") << '\n';
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    vector<__int128> powers = {1};
    for (int i = 1; i <= 64; i++)
    {
        powers.push_back(powers.back() * 2);
    }
    reachable.insert(0);
    for (int i = 0; i < powers.size(); i++)
    {
        jump(i + 1, powers[i], -1, powers);
        jump(i + 1, -powers[i], +1, powers);
    }
    while (t--)
        solve();
}