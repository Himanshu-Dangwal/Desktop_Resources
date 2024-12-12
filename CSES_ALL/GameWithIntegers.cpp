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

        if (n % 3 == 0) {
            cout << "Second\n";
        }
        else {
            cout << "First\n";
        }
    }
    return 0;
}