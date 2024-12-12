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
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        string s, t;
        cin >> s >> t;
        if (s.find(t) != string::npos) {
            cout << "0\n";
            continue;
        }
        int cnt = 0;
        while (s.size() < 4 * t.size() || cnt == 0) {
            s += s;
            cnt++;

            if (s.find(t) != string::npos) {
                break;
            }
        }

        if (s.find(t) != string::npos) {
            cout << cnt << endl;
        }
        else {
            cout << "-1\n";
        }
    }
    return 0;
}