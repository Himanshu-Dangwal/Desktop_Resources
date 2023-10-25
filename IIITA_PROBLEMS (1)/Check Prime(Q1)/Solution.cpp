#include <bits/stdc++.h>
using namespace std;
unordered_set<string> prime = {"2", "3", "5", "7"};
int alt_value(string &s)
{
    int ans = 0;
    for (int i = 0; i < s.size(); i += 2)
    {
        ans += (int)(s[i] - '0');
    }
    for (int i = 1; i < s.size(); i += 2)
    {
        ans -= (int)(s[i] - '0');
    }
    return abs(ans);
}
void solve()
{
    string s;
    cin >> s;
    while (s.length() > 1)
    {
        s = to_string(alt_value(s));
    }
    cout << (prime.count(s) ? "YES" : "NO") << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
}