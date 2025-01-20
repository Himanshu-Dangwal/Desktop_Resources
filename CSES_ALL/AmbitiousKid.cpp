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
    int ans = INT_MAX;

    for (int i = 0;i < n;i++) {
        int x;
        cin >> x;

        ans = min(ans, abs(x));
    }

    cout << ans;
    return 0;
}


//FInding Set Count (Hashing)

#define pii pair<int,int>
#define f first
#define s second
class Solution {
public:
    int n, m;
    bool check(vector<vector<int>>& mat, int x, int y) {
        bool check = true;
        //Check row
        for (int j = 0;j < m;j++) {
            if (mat[x][j] != 0) {
                check = false;
                break;
            }
        }

        if (check) return true;
        check = true;
        // cout<<"HEre"<<endl;
        //Check col
        for (int i = 0;i < n;i++) {
            if (mat[i][y] != 0) {
                check = false;
                break;
            }
        }
        if (check) return true;
        return false;
    }

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        n = mat.size(), m = mat[0].size();
        map<int, pii> mp;

        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                mp[mat[i][j]] = { i,j };
            }
        }

        vector<int> setCountX(n, 0), setCountY(m, 0);

        for (int i = 0;i < arr.size();i++) {
            int x = mp[arr[i]].f, y = mp[arr[i]].s;
            // cout<<x<<" "<<y<<endl;
            // mat[x][y] = 0;
            // if(check(mat,x,y)) return i;
            setCountX[x]++;
            setCountY[y]++;
            // cout<<setCountX[x]<<" "<<setCountX[y]<<endl;
            if ((setCountX[x] == (m)) || (setCountY[y] == (n))) return i;
        }

        return -1;
    }
};