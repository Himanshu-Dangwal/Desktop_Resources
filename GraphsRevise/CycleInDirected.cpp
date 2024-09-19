//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool isCycle(int src, vector<bool> &visited, vector<int> &stack, vector<int> adj[])
    {
        visited[src] = true;
        stack[src] = 1;

        for (auto adjEle : adj[src])
        {
            if (!visited[adjEle] && isCycle(adjEle, visited, stack, adj))
            {
                return true;
            }
            else
            {
                if (visited[adjEle] && stack[adjEle] == 1)
                {
                    return true;
                }
            }
        }

        stack[src] = 0;
        return false;
    }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        vector<int> stack(V, 0);
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && isCycle(i, visited, stack, adj))
            {
                return true;
            }
        }

        return false;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends