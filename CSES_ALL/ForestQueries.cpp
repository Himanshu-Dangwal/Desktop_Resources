#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
// find_by_order() 
// order_of_key()

int n, q;
int main()
{
    cin >> n >> q;
    vector<vector<char>> arr(n + 1, vector<char>(n + 1));
    vector<vector<int>> prefix(n + 1, vector<int>(n + 1, 0));

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '*') {
                prefix[i][j] = 1;
            }
        }
    }

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            if (i == 1) {
                if (prefix[i][j]) {
                    prefix[i][j] += prefix[i][j - 1];
                }
                else {
                    prefix[i][j] = prefix[i][j - 1];
                }
            }
            else if (j == 1) {
                if (prefix[i][j] == 1) {
                    prefix[i][j] = prefix[i - 1][j] + 1;
                }
                else {
                    prefix[i][j] = prefix[i - 1][j];
                }
            }
            else {
                prefix[i][j] += prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }
    }

    // for (int i = 1;i <= n;i++) {
    //     for (int j = 1;j <= n;j++) {
    //         cout << prefix[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1] << endl;
    }
    return 0;
}