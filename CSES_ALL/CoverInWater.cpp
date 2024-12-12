#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
// find_by_order() 
// order_of_key()


int main()
{
    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        string s;
        cin >> s;
        ll longest = 0;
        ll pAns = 0;
        for (int i = 0;i < n;) {
            if (s[i] == '.') {
                int j = i;
                while (j < n && s[i] == s[j]) j++;
                if (j - i > longest) longest = j - i;
                pAns += j - i;
                i = j;
            }
            else {
                i++;
            }
        }

        if (longest == 0) {
            cout << 0 << endl;
        }
        else if (longest > 2) {
            cout << "2\n";
        }
        else {
            cout << pAns << endl;
        }
    }
    return 0;
}