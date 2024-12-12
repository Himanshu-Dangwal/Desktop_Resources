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

        vector<int> arr(n);
        int flag = 0;
        for (int i = 0;i < n;i++) {
            cin >> arr[i];
            if (arr[i] == m) flag = 1;
        }

        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}