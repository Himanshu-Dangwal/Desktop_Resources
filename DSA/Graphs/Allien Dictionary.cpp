class Solution{
    public:
    
    void dfs(int src,vector<vector<int>> &adj,vector<int> &visited,string &ans){
        
        visited[src] = true;
        
        for(auto child : adj[src]){
            if(!visited[child]){
                dfs(child,adj,visited,ans);
            }
        }
        char res = src + 'a';
        ans = res + ans;
        return;
    }
    
    string findOrder(string dict[], int N, int k) {
        vector<vector<int>> adj(k);
        
        for(int i=0;i<N-1;i++){
            string word1 = dict[i];
            string word2 = dict[i+1];
            
            int min_len = min(word1.length(),word2.length());
            
            for(int j=0;j<min_len;j++){
                if(word1[j] != word2[j]){
                    adj[word1[j]-'a'].push_back(word2[j]-'a');
                    break;
                }
            }
        }
        
        string ans = "";
        vector<int> visited(k,0);
        
        for(int i=0;i<k;i++){
            if(!visited[i]){
                dfs(i,adj,visited,ans);
            }
        }
        return ans;
    }
};
