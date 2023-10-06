#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

vector<int> adj[10000];
int timer;
bool visited[10000];
int low[1000];
int in[1000];
unordered_map<int,int> mp;

void dfs(int node,int par){
	visited[node] = true;
	in[node] = low[node] = timer;
	timer++;
	
	int bc = 0;
	
	for(int child : adj[node]){
		if(child == par) continue;
		if(visited[child])
			low[node] = min(low[node],in[child]);
		else{
			dfs(child,node);
			low[node] = min(low[node],low[child]);
			
			if(low[child] > in[node]){
				//Bridge::
				
//				cout<<"Bridge Found Between "<<node<<" - > "<<child<<endl;

				mp[node] = child;
				mp[child] = node;
				bc++;
			}	
		}	
	}
	
}

//
//fun(){
//	
//	int maxi = 0;
//	
//	for(int i=0;i<edges.size();i++){
//		int x = edges[i][0];
//		int y = edges[i][1];
//		
//		maxi = max(maxi,max(x,y));
//		
//				
//		adj[x].push_back(y)l
//	}
//	
//}


fun(){
	
	
	int timer = 0;
	vector<bool> visited(100000,false);
	vector<int> low(100000,0);
	
	
	for(int i=0;i<10000;i++){
		adj[i].clear();
	}
	
	
}








void get_path(int u, int d,vector<bool> &visited,int& path_index,vector<vector<int>> &paths,vector<int> &path)
{
    
    visited[u] = true;
    path[path_index] = u;
    path_index++;
 
    if (u == d) {
        paths.push_back(path)
    }
    else 
    {
        
        for (auto i : adj[u])
            if (!visited[i])
                get_path(i, d, visited, path_index, paths,path);
    }

    path_index--;
    visited[u] = false;
}


cout<<mp[4]<<endl;

//if(paths.size()){
//	for(int i=0;i<paths[0].size();i++){
//		cout<<paths[0][i]<<" ";
//	}
//	cout<<endl;
//}


for(int src = 1; src<= maxi;src++){
	for(int dest=1;dest <= maxi;dest++){
		
		if(src == dest) continue;
		
		vector<vector<int>> paths;
		
		vector<int> path(maxi+1,0);
		
		int path_idx = 0;
		
		vector<bool> visited(maxi+1,false);
		
		get_path(src,dest,visited,path_idx,paths,path);
		
		int res = 0;
		
		for(int i=0;i<paths.size();i++){
			int cnt = 0;
			for(int j=0;j<paths[i].size();j++){
				
				if(mp.find(paths[i][j]) != mp.end()){
					if(mp[paths[i][j]] == paths[i][j+1]){
						cnt++;
					}
				}
				
			}
			
			if(cnt == 1){
				res++;
			}
			
		}
		
	}
}









int main(){
	
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++){
		int x,y;
		cin>>s>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	dfs(1,-1);
	
	return 0;
}

