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

void solve() {
    char arr[10][10];
    for (int i = 0;i < 10;i++) {
        for (int j = 0;j < 10;j++) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;

    for (int i = 0;i < 10;i++) {
        for (int j = 0;j < 10;j++) {
            if (arr[i][j] == 'X') {
                int x = i + 1, y = j + 1;

                if (x == 1 || x == 10 || y == 1 || y == 10) {
                    ans += 1;
                }
                else if (x == 2 || x == 9 || y == 2 || y == 9) {
                    ans += 2;
                }
                else if (x == 3 || x == 8 || y == 3 || y == 8) {
                    ans += 3;
                }
                else if (x == 4 || x == 7 || y == 4 || y == 7) {
                    ans += 4;
                }
                else {
                    ans += 5;
                }

            }
        }
    }

    cout << ans << endl;
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