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
    vector<int> houses(n);

    for (int i = 0;i < n;cin >> houses[i++]);
    sort(houses.begin(), houses.end());

    vector<int> station;
    int i = 0;
    while (i < n) {
        int base = houses[i] + 4;
        station.push_back(base);

        while (i < n && houses[i] < (base + 4)) i++;
    }

    for (int base : station) cout << base << " ";
    return;
}

int main()
{
    solve();
    return 0;
}