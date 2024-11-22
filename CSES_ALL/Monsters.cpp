#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
#define pii pair<ll,ll>
#define f first
#define s second
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
// find_by_order() 
// order_of_key()

const int maxN = 2e5;
int n, m, si, sj, dirX[4] = { 0,0,-1,1 }, dirY[4] = { -1,1,0,0 };
vector<vector<char>> arr(1005, vector<char>(1005));
vector<vector<int>> grid(1005, vector<int>(1005, INT_MAX));
vector<vector<bool>> vis(1005, vector<bool>(1005, false));
vector<vector<bool>> vis2(1005, vector<bool>(1005, false));
map<pii, int> mp;
char dirChar[4] = { 'L','R','U','D' };

vector<int> par(maxN);


int main() {
    cin >> n >> m;
    queue<pair<int, pii>> q;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'M') q.push({ 0,{i,j} }), vis[i][j] = true;
            if (arr[i][j] == 'A') si = i, sj = j;
        }
    }

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        int x = curr.s.f, y = curr.s.s, currTime = curr.f;
        // cout << x << " " << y << endl;
        if (grid[x][y] <= currTime) continue;
        grid[x][y] = min(grid[x][y], currTime);
        for (int i = 0;i < 4;i++) {
            int nx = x + dirX[i], ny = y + dirY[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && arr[nx][ny] != '#' && (grid[nx][ny] > (currTime + 1))) {
                q.push({ currTime + 1,{nx,ny} });
                vis[nx][ny] = true;
            }
        }

    }

    // for (int i = 0;i < n;i++) {
    //     for (int j = 0;j < m;j++) {
    //         if (grid[i][j] == INT_MAX) {
    //             cout << "M" << " ";
    //             continue;
    //         }
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    queue < pair<int, pii>> q2;
    q2.push({ 0, {si,sj} });
    bool flag = false;
    mp[{si, sj}] = -1;
    pii last;
    while (!q2.empty()) {
        auto curr = q2.front();
        q2.pop();
        int x = curr.s.f, y = curr.s.s, currTime = curr.f;
        // cout << x << " " << y << endl;
        if (x == n - 1 || y == m - 1 || x == 0 || y == 0) {
            flag = true;
            cout << "YES" << endl;
            last = { x,y };
            break;
        }

        vis2[x][y] = true;
        for (int i = 0;i < 4;i++) {
            int nx = x + dirX[i], ny = y + dirY[i];
            // string toAdd = "D";
            // if (i == 0) toAdd = "L";
            // if (i == 1) toAdd = "R";
            // if (i == 2) toAdd = "U";
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis2[nx][ny] && arr[nx][ny] != '#' && grid[nx][ny] >(1 + currTime)) {
                q2.push({ currTime + 1,{nx,ny} });
                // curr.s.s + toAdd
                mp[{nx, ny}] = i;
            }
        }
    }

    if (flag) {
        string ans = "";
        while (mp[last] != -1) {
            ans.push_back(dirChar[mp[last]]);
            int i = mp[last];
            if (i == 0) {
                last.s += 1;
            }
            else if (i == 1) {
                last.s -= 1;
            }
            else if (i == 2) {
                last.f += 1;
            }
            else {
                last.f -= 1;
            }
        }
        // ans.push_back(dirChar[mp[last]]);
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        cout << ans;
    }

    // queue<pair<int, pair<pii, string>>> q2;
    // q2.push({ 0,{{si,sj},""} });
    // bool flag = false;
    // while (!q2.empty()) {
    //     auto curr = q2.front();
    //     q2.pop();
    //     int x = curr.s.f.f, y = curr.s.f.s, currTime = curr.f;
    //     // cout << x << " " << y << endl;
    //     if (x == n - 1 || y == m - 1 || x == 0 || y == 0) {
    //         flag = true;
    //         cout << "YES" << endl;
    //         cout << curr.s.s.size() << endl;
    //         cout << curr.s.s;
    //         break;
    //     }

    //     vis2[x][y] = true;
    //     for (int i = 0;i < 4;i++) {
    //         int nx = x + dirX[i], ny = y + dirY[i];
    //         string toAdd = "D";
    //         if (i == 0) toAdd = "L";
    //         if (i == 1) toAdd = "R";
    //         if (i == 2) toAdd = "U";
    //         if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis2[nx][ny] && arr[nx][ny] != '#' && grid[nx][ny] >(1 + currTime)) {
    //             q2.push({ currTime + 1,{{nx,ny},curr.s.s + toAdd} });
    //         }
    //     }
    // }


    if (!flag) {
        cout << "NO";
    }

    return 0;
}




