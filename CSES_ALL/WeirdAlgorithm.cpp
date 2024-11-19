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
    ll n;
    cin >> n;

    cout << n << " ";
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        }
        else {
            n *= 3;
            n++;
        }
        cout << n << " ";
    }
    return 0;
}
