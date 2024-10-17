// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n"
// #define MOD 1000000007
// typedef long long ll;

// void dfs(int node, vector<vector<int>> &adj, vector<int> &in, vector<int> &low, int timer, int par, vector<bool> &visited)
// {
//     timer++;
//     in[node] = low[node] = timer;
//     visited[node] = true;

//     for (auto child : adj[node])
//     {
//         if (child == par)
//             continue;

//         if (visited[child])
//         {
//             low[node] = min(low[node], in[child]);
//         }
//         else
//         {
//             dfs(child, adj, in, low, timer + 1, node, visited);

//             if (in[node] < low[child])
//             {
//                 cout << node << " -> " << child << endl;
//             }

//             low[node] = min(low[node], low[child]);
//         }
//     }
// }

// void bridges(vector<vector<int>> &adj)
// {
//     int n = adj.size();
//     vector<bool> visited(n, false);
//     vector<int> in(n, 0), low(n, 0);

//     for (int i = 0; i < n; i++)
//     {
//         if (!visited[i])
//         {
//             dfs(i, adj, in, low, 0, -1, visited);
//         }
//     }
// }

// void solve()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<vector<int>> adj(n);

//     for (int i = 0; i < n; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         adj[x].push_back(y);
//     }

//     bridges(adj);
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }

class Solution
{
    int timer = 0;

private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &in, vector<int> &low, vector<bool> &visited, int par, vector<vector<int>> &ans)
    {
        visited[node] = true;
        in[node] = low[node] = timer;
        timer++;
        for (auto child : adj[node])
        {
            if (child == par)
                continue;

            if (visited[child])
            {
                low[node] = min(low[node], in[child]);
            }
            else
            {
                dfs(child, adj, in, low, visited, node, ans);

                int n = in.size();
                // for(int i=0;i<n;i++){
                //     cout<<in[i]<<" ";
                // }
                // cout<<endl;

                // for(int i=0;i<n;i++){
                //     cout<<low[i]<<" ";
                // }
                // cout<<endl;
                if (low[child] > in[node])
                {
                    // cout<<"Found"<<endl;
                    ans.push_back({child, node});
                }

                low[node] = min(low[node], low[child]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> ans;
        vector<bool> visited(n, false);

        vector<int> in(n, 0), low(n, 0);

        vector<vector<int>> adj(n);

        for (int i = 0; i < connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        dfs(0, adj, in, low, visited, -1, ans);
        return ans;
    }
};