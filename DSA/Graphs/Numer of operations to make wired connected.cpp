class Solution {
public:
    
    void dfs(int src,int n,vector<vector<int>>&arr,vector<int> &visited){
        visited[src] = 1;
        
        for(auto child : arr[src]){
            if(!visited[child])
                dfs(child,n,arr,visited);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> arr(n);
        
        if(connections.size() < n-1)
            return -1;
        
        for(int i=0;i<connections.size();i++){
            int x = connections[i][0];
            int y = connections[i][1];
            
            arr[x].push_back(y);
            arr[y].push_back(x);
        }
        
        vector<int> visited(n,0);
        
        int count = 0;
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,n,arr,visited);
                count++;
            }
        }
        return count-1;
    }
};
