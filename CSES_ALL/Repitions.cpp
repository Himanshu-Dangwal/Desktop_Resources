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
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0;
    for (int i = 0;i < n;) {
        int j = i;
        while (j < n && (s[i] == s[j])) j++;
        ans = max(ans, j - i);
        i = j;
    }
    cout << ans;
    return 0;
}