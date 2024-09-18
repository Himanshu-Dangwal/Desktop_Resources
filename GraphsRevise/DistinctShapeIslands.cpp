//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void dfs(int x, int y, int baseX, int baseY, vector<vector<int>> &grid, vector<pair<int, int>> &vp)
    {
        int n = grid.size();
        int m = grid[0].size();
        int dirX[4] = {0, 0, -1, 1};
        int dirY[4] = {1, -1, 0, 0};

        vp.push_back({x - baseX, y - baseY});
        grid[x][y] = 0;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dirX[i];
            int ny = y + dirY[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                continue;
            }
            else
            {
                if (grid[nx][ny] == 1)
                {
                    dfs(nx, ny, baseX, baseY, grid, vp);
                }
            }
        }
    }

    int countDistinctIslands(vector<vector<int>> &grid)
    {
        // code here
        int n = grid.size();
        int m = grid[0].size();

        set<vector<pair<int, int>>> st;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    vector<pair<int, int>> vp;
                    dfs(i, j, i, j, grid, vp);
                    st.insert(vp);
                }
            }
        }

        return st.size();
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends