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

int count(int n, vector<int>& cost) {
    int groups = 0;

    int l = 0, r = cost.size() - 1;

    while (l <= r) {
        if (l == r) {
            if (cost[l] == n) groups++;
            break;
        }

        if (cost[l] == n) {
            groups++;
            l++;
        }
        else if (cost[r] == n) {
            groups++;
            r--;
        }
        else if (cost[l] + cost[r] == n) {
            groups++;
            l++;
            r--;
        }
        else if (cost[l] + cost[r] > n) {
            r--;
        }
        else {
            l++;
        }
    }
    return groups;
}

int findMaxi(vector<int>& cost) {
    sort(cost.begin(), cost.end());


    int low = cost[0];
    int n = cost.size();

    if (n == 1) return 1;
    if (n == 2) {
        if (cost[0] == cost[1]) return 2;
        return 1;
    }
    int high = cost[n - 1] + cost[n - 2];
    int ans = 1;
    for (int i = low;i <= high;i++) {
        ans = max(ans, count(i, cost));
        // cout << i << " " << ans << endl;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> cost(n);
    for (int i = 0;i < n;cin >> cost[i++]);

    cout << findMaxi(cost);
    return 0;
}