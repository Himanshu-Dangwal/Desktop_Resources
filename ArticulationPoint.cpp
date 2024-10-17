//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    int timer = 0;

private:
    void dfs(int node, vector<int> &in, vector<int> &low, vector<int> adj[], vector<bool> &visited, int par, unordered_set<int> &articulation_nodes)
    {
        visited[node] = true;
        in[node] = low[node] = timer;
        timer++;
        int neighbours = 0;
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
                dfs(child, in, low, adj, visited, node, articulation_nodes);

                if (low[child] >= in[node] && par != -1)
                {
                    articulation_nodes.insert(node);
                }

                low[node] = min(low[node], low[child]);

                neighbours++;
            }
        }

        if (neighbours > 1 && par == -1)
        {
            articulation_nodes.insert(node);
        }
    }

public:
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        vector<int> ans;
        unordered_set<int> articulation_nodes;
        vector<int> in(V, 0), low(V, 0);
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, in, low, adj, visited, -1, articulation_nodes);
            }
        }

        if (articulation_nodes.size() == 0)
            return {-1};

        for (auto node : articulation_nodes)
        {
            ans.push_back(node);
        }
        sort(ans.begin(), ans.end());
        return ans;
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
        vector<int> ans = obj.articulationPoints(V, adj);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends