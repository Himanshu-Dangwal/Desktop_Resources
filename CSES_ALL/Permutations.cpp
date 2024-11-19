#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
#define pii pair<int,int>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
// find_by_order() 
// order_of_key()


int main()
{
    int n;
    cin >> n;
    int even, odd;
    if (n % 2 == 0) even = n, odd = n - 1;
    else even = n - 1, odd = n;
    if (n == 1) {
        cout << "1";
        return 0;
    }
    if (n <= 3) {
        cout << "NO SOLUTION";
        return 0;
    }

    if (n == 4) {
        cout << "2 4 1 3";
        return 0;
    }

    while (even >= 2) {
        cout << even << " ";
        even -= 2;
    }

    while (odd >= 1) {
        cout << odd << " ";
        odd -= 2;
    }
    return 0;
}