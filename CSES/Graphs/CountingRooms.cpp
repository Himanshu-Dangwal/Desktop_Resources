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

int vis[1005][1005];
int dirX[4] = { 0,0,-1,1 };
int dirY[4] = { -1,1,0,0 };
int n, m;
void dfs(int x, int y, vector<vector<char>>& arr) {
    vis[x][y] = true;

    for (int i = 0;i < 4;i++) {
        int nx = x + dirX[i];
        int ny = y + dirY[i];

        if (nx < n && ny < m && nx >= 0 && ny >= 0 && !vis[nx][ny] && arr[nx][ny] == '.') {
            dfs(nx, ny, arr);
        }
    }
}

int main()
{
    cin >> n >> m;

    vector<vector<char>> arr(n, vector<char>(m));;
    memset(vis, false, sizeof(vis));
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (arr[i][j] == '.' && !vis[i][j]) {
                dfs(i, j, arr);
                ans++;
            }
        }
    }

    cout << ans;
    return 0;
}