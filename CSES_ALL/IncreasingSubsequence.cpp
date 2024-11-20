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
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0;i < n;cin >> arr[i++]);

    vector<int> temp;
    temp.push_back(arr[0]);

    for (int i = 1;i < n;i++) {
        if (arr[i] > temp.back()) {
            temp.push_back(arr[i]);
        }
        else {
            int idx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[idx] = arr[i];
        }
    }

    cout << temp.size();
    return 0;
}