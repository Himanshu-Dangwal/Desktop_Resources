#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
// find_by_order() 
// order_of_key()


void solve() {
    int n;
    cin >> n;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0;i < 2 * n;i++) {
        int x;
        cin >> x;
        if (x == 0) cnt0++;
        else cnt1++;
    }

    int maxi = min(cnt0, cnt1);
    int rem1 = cnt0 % 2;
    int rem2 = cnt1 % 2;

    int mini = (rem1 + rem2) / 2;
    cout << mini << " " << maxi << endl;
    return;
}

int main()
{
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

// maxi = min(count0,count1)
// mini = (count0NotPaired+count1NotPaired)/2;