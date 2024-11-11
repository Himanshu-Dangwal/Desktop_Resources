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
int dfs(vector<vector<bool>>& vis, int x, int y, int cnt) {

    vis[x][y] = true;
    cnt++;
    int n = vis.size();

    if (x == n - 1 && y == n - 1) {
        vis[x][y] = false;
        if (cnt == 2 * n) return 1;
        return 0;
    }

    int dirX[4] = { 1,-1,0,0 };
    int dirY[4] = { 0,0,-1,1 };
    int ans = 0;
    for (int i = 0;i < 4;i++) {
        int nx = x + dirX[i];
        int ny = y + dirY[i];

        if (nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny]) {
            ans += dfs(vis, nx, ny, cnt);
        }
    }
    vis[x][y] = false;
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<bool>> vis(n, vector<bool>(n, false));
    vis[0][0] = true;
    cout << 2 * dfs(vis, 1, 0, 1);
    return 0;
}



