//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool dfs(int src, vector<int> adj[], vector<bool> &visited, vector<int> &color, int curr)
    {
        visited[src] = true;
        color[src] = curr;

        for (auto adjNode : adj[src])
        {
            if (!visited[adjNode])
            {
                if (!dfs(adjNode, adj, visited, color, curr ^ 1))
                {
                    return false;
                }
            }
            else
            {
                if (color[adjNode] != (curr ^ 1))
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> visited(V, false);
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (!dfs(i, adj, visited, color, 0))
                {
                    return false;
                }
            }
        }

        return true;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends