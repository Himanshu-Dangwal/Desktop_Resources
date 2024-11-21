// #include <bits/stdc++.h>
// using namespace std;
// #pragma GCC target("popcnt")
// #define endl "\n"
// #define MOD 1000000007
// typedef long long ll;
// typedef long long int lli;
// #define pii pair<ll,ll>
// #define f first
// #define s second
// // #include <ext/pb_ds/assoc_container.hpp>
// // using namespace __gnu_pbds;
// // typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
// // find_by_order() 
// // order_of_key()
// lli a, b;
// ll dp1[20][11][2];
// ll dp2[20][11][2];

// ll solve1(int n, string& s, bool tight, int lastUsed) {

//     if (n == 1) {
//         if (!tight) return 9;
//         int lastVal = s[s.length() - 1] - '0';
//         if (lastUsed < lastVal) {
//             return lastVal;
//         }
//         return lastVal + 1;
//     }

//     if (dp1[n][lastUsed][tight] != -1) {
//         return dp1[n][lastUsed][tight];
//     }

//     ll ans = 0;
//     if (tight) {

//         if (lastUsed == -1) {
//             ll limit = s[s.length() - n] - '0';
//             for (int i = 0;i <= limit;i++) {
//                 if (i == limit) ans += solve1(n - 1, s, 1, i);
//                 else ans += solve1(n - 1, s, 0, i);
//             }
//         }
//         else {
//             ll limit = s[s.length() - n] - '0';
//             for (int i = 0;i <= limit;i++) {
//                 if (lastUsed != 0 && i == lastUsed) continue;
//                 if (i == limit) ans += solve1(n - 1, s, 1, i);
//                 else ans += solve1(n - 1, s, 0, i);
//             }
//         }

//     }
//     else {
//         for (int i = 0;i <= 9;i++) {
//             if (lastUsed != 0 && i == lastUsed) continue;
//             ans += solve1(n - 1, s, 0, i);
//         }
//     }

//     return dp1[n][lastUsed][tight] = ans;

// }

// ll solve2(int n, string& s, bool tight, int lastUsed) {

//     if (n == 1) {
//         if (!tight) return 9;
//         int lastVal = s[s.length() - 1] - '0';
//         if (lastUsed < lastVal) {
//             return lastVal;
//         }
//         return lastVal + 1;
//     }

//     if (dp2[n][lastUsed][tight] != -1) {
//         return dp2[n][lastUsed][tight];
//     }

//     ll ans = 0;
//     if (tight) {

//         if (lastUsed == -1) {
//             ll limit = s[s.length() - n] - '0';
//             for (int i = 0;i <= limit;i++) {
//                 if (i == limit) ans += solve1(n - 1, s, 1, i);
//                 else ans += solve1(n - 1, s, 0, i);
//             }
//         }
//         else {
//             ll limit = s[s.length() - n] - '0';
//             for (int i = 0;i <= limit;i++) {
//                 if (lastUsed != 0 && i == lastUsed) continue;
//                 if (i == limit) ans += solve1(n - 1, s, 1, i);
//                 else ans += solve1(n - 1, s, 0, i);
//             }
//         }

//     }
//     else {
//         for (int i = 0;i <= 9;i++) {
//             if (lastUsed != 0 && i == lastUsed) continue;
//             ans += solve1(n - 1, s, 0, i);
//         }
//     }

//     return dp2[n][lastUsed][tight] = ans;

// }

// int main()
// {
//     cin >> a >> b;
//     // a--;
//     string s1 = to_string(a);
//     string s2 = to_string(b);
//     memset(dp1, -1, sizeof(dp1));
//     memset(dp2, -1, sizeof(dp2));

//     int n = s1.length();
//     int m = s2.length();
//     // cout << s1 << endl;
//     // cout << s2 << endl;
//     cout << solve1(m, s2, 1, -1) - solve2(n, s1, 1, -1) + 1;
//     // cout << ans;
//     // string s;
//     // cin >> s;
//     // cout << solve1(3, s, 1, -1) << endl;

//     // string s2;
//     // cin >> s2;
//     // cout << solve2(3, s2, 1, -1) - solve1(3, s, 1, -1) + 1;


// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[20][10][2][2];

ll mem(string s, ll curr, ll prev_digit, ll leading_zero, ll tight)
{
    if (curr == 0)
    {
        return 1;
    }

    if (dp[curr][prev_digit][leading_zero][tight] != -1)
        return dp[curr][prev_digit][leading_zero][tight];

    ll limit;
    if (tight == 0)
    {
        limit = 9;
    }
    else
    {
        ll sz = s.size();
        limit = s[sz - curr] - 48;
    }

    ll countNumbers = 0;

    for (ll curr_digit = 0; curr_digit <= limit; curr_digit++)
    {
        if (leading_zero == 0 && (curr_digit == prev_digit))
        {
            continue;
        }

        ll new_leading_zero = (leading_zero == 1 && curr_digit == 0) ? 1 : 0;
        ll new_tight = (curr_digit == limit && tight == 1) ? 1 : 0;

        countNumbers += mem(s, curr - 1, curr_digit, new_leading_zero, new_tight);
    }

    dp[curr][prev_digit][leading_zero][tight] = countNumbers;

    return dp[curr][prev_digit][leading_zero][tight];
}

int main()
{
    ll a, b;
    cin >> a >> b;

    ll count1 = 0;
    memset(dp, -1, sizeof(dp));

    string str1 = to_string(a - 1);
    if (a != 0)
        count1 = mem(str1, str1.size(), -1, 1, 1);

    memset(dp, -1, sizeof(dp));
    string str2 = to_string(b);
    ll count2 = mem(str2, str2.size(), -1, 1, 1);

    cout << count2 - count1;
}