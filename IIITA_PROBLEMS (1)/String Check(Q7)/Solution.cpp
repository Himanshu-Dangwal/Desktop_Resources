#include <bits/stdc++.h>
#define int long long int
using namespace std;
int dist[102][102];
int floyd_warshall(vector<vector<int>> &common, vector<vector<int>> &hash, int d)
{
    int n = common.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = 1 + (common[i][j] - min(hash[i][d], hash[j][d])) * (common[i][j] - min(hash[i][d], hash[j][d]));
            if (i == j)
                dist[i][j] = 0;
        }
    }
    int ans = 0;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            ans += dist[i][j];
    }
    return ans;
}
signed main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<int>> hash(n, vector<int>(26, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            hash[i][v[i][j] - 'a']++;
        }
    }
    vector<vector<int>> common(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int l = 0;
            for (int k = 0; k < 26; k++)
                l += min(hash[i][k], hash[j][k]);
            common[i][j] = l;
        }
    }
    int ans = INT_MAX;
    int ans1 = -1;
    for (int c = 0; c < 26; c++)
    {
        int dis = floyd_warshall(common, hash, c);
        if (dis < ans)
        {
            ans = dis;
            ans1 = c;
        }
    }
    cout << ans << ' ' << (((char)('a' + ans1))) << endl;
}