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
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0;i < n;cin >> arr[i++]);

        if (n == 2) { cout << "YES\n"; continue; }

        map<int, int> mp;
        for (int x : arr) mp[x]++;

        if (mp.size() > 2) {
            cout << "NO\n";
        }
        else {
            if (mp.size() == 1) {
                cout << "YES\n";
            }
            else {
                vector<int> temp;
                for (auto it : mp) {
                    temp.push_back(it.second);
                }
                // cout << temp[0] << " " << temp[1] << endl;

                if (abs(temp[0] - temp[1]) <= 1) {
                    cout << "YES\n";
                }
                else {
                    cout << "NO\n";
                }
            }
        }
    }
    return 0;
}