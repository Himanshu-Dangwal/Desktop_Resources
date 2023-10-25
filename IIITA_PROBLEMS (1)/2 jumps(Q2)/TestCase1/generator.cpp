#include "testlib.h"
#include <bits/stdc++.h>
#define int __int128
using namespace std;
#define nl '\n'
set<long long> reachable;
void jump(int ind, int last, int sign, vector<__int128> &powers)
{
    // cout<<last<<' ';
    if (last > 1e18 || last < -1e18)
        return;
    reachable.insert(last);
    jump(ind + 1, last + sign * powers[ind], sign * -1, powers);
}
signed main(int64_t argc, char *argv[])
{
    registerGen(argc, argv, 1);
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
    cout << reachable.size() << endl;
    string x;
    cin >> x;
    ofstream out("TestCase" + x + "/input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    out << 100000 << nl;
    for (int i = 0; i < 100000; i++)
    {
        int64_t a = rnd.next(-1e18, 1e18);
        while (reachable.count(a))
            a = rnd.next(-1e18, 1e18);
        out << a << nl;
    }
    out.close();
}