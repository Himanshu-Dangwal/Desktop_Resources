// #include <bits/stdc++.h>
// using namespace std;
// #pragma GCC target("popcnt")
// #define endl "\n"
// #define MOD 1000000007
// typedef long long ll;
// // #include <ext/pb_ds/assoc_container.hpp>
// // using namespace __gnu_pbds;
// // typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
// // find_by_order() 
// // order_of_key()

// int vis[1005][1005];
// int dirX[4] = { 0,0,-1,1 };
// int dirY[4] = { -1,1,0,0 };
// int n, m, ei, ej;
// string finalPath = "";
// int finalDistance = INT_MAX;
// bool reached = false;
// void dfs(int x, int y, vector<vector<char>>& arr, int cnt, string& path) {
//     vis[x][y] = true;
//     if (x == ei && y == ej) {
//         reached = true;
//         if (cnt < finalDistance) {
//             finalPath = path;
//             finalDistance = cnt;
//         }
//         vis[x][y] = false;
//         return;
//     }
//     for (int i = 0;i < 4;i++) {
//         int nx = x + dirX[i];
//         int ny = y + dirY[i];

//         if (nx < n && ny < m && nx >= 0 && ny >= 0 && !vis[nx][ny] && (arr[nx][ny] == '.' || arr[nx][ny] == 'B')) {
//             if (i == 0) path += "L";
//             else if (i == 1) path += "R";
//             else if (i == 2) path += "U";
//             else path += "D";
//             dfs(nx, ny, arr, cnt + 1, path);
//             path.pop_back();
//         }
//     }

//     vis[x][y] = false;
// }

// int main()
// {
//     cin >> n >> m;

//     vector<vector<char>> arr(n, vector<char>(m));
//     int si, sj;
//     memset(vis, false, sizeof(vis));
//     for (int i = 0;i < n;i++) {
//         for (int j = 0;j < m;j++) {
//             cin >> arr[i][j];

//             if (arr[i][j] == 'A') si = i, sj = j;
//             if (arr[i][j] == 'B') ei = i, ej = j;
//         }
//     }
//     // cout << si << " " << sj << " " << ei << " " << ej << endl;
//     int ans = 0;
//     string path = "";
//     int cnt = 0;
//     dfs(si, sj, arr, cnt, path);

//     if (reached) {
//         cout << "YES" << endl;
//         cout << finalDistance << endl;
//         cout << finalPath;
//     }
//     else {
//         cout << "NO";
//     }
//     return 0;
// }

#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;

char ar[1001][1001];
char br[1001][1001];
bool vis[1001][1001];
int n, m;
vector<char> path;

bool isValid(int x, int y) {

    if (x < 1 || x > n || y < 1 || y > m) return false;

    if (ar[x][y] == '#' || vis[x][y] == true) return false;

    return true;
}

bool bfs(int x, int y)
{
    queue<pair<int, int> > q;
    q.push({ x , y });
    vis[x][y] = true;

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        if (ar[a][b] == 'B') {
            while (1) {
                path.push_back(br[a][b]);

                if (path.back() == 'L') b++;
                if (path.back() == 'R') b--;
                if (path.back() == 'U') a++;
                if (path.back() == 'D') a--;

                if (a == x && b == y)
                    break;
            }
            return true;
        }

        //left
        if (isValid(a, b - 1)) br[a][b - 1] = 'L', q.push({ a , b - 1 }), vis[a][b - 1] = true;

        //right
        if (isValid(a, b + 1)) br[a][b + 1] = 'R', q.push({ a , b + 1 }), vis[a][b + 1] = true;

        //up
        if (isValid(a - 1, b)) br[a - 1][b] = 'U', q.push({ a - 1 , b }), vis[a - 1][b] = true;

        //down
        if (isValid(a + 1, b)) br[a + 1][b] = 'D', q.push({ a + 1 , b }), vis[a + 1][b] = true;

    }

    return false;
}



int main()
{
    cin >> n >> m;
    int x;
    int y;

    REP(i, n) REP(j, m) {
        cin >> ar[i][j];
        if (ar[i][j] == 'A') x = i, y = j;
    }

    if (bfs(x, y) == true) {
        cout << "YES" << endl << path.size() << endl;
        while (path.size() > 0) cout << path.back(), path.pop_back();
    }
    else {
        cout << "NO";
    }
}
