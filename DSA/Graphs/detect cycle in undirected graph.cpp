#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;


bool DFS(int src,int parent,vector<vector<int>> &adj,vector<int> &visited){
	
	visited[src] = true;
	
	for(auto child : adj[src]){
		if(child == parent)
			continue;
		if(visited[child])
			return true;
		
		return DFS(child,src,adj,visited);	
	}
	return false;
}

bool isCycle(int n,vector<vector<int>> &adj){
	
	vector<int> visited(n,0);
	
	for(int i=0;i<n;i++){
		if(!visited[i]){
			bool ans = DFS(i,-1,adj,visited);
			if(ans)
				return true;
		}
	}
	return false;
}

int main(){
	int n,e;
	cin>>n>>e;
	
	vector<vector<int>> adj(n);
	
	for(int i=0;i<e;i++){
		int src,dest;
		cin>>src>>dest;
		
		adj[src].push_back(dest);
		adj[dest].push_back(src);
	}
	
	if(isCycle(n,adj)){
		cout<<"Cycle exists"<<endl;
	}else{
		cout<<"Cycle Doesn't Exists"<<endl;
	}

	return 0;
}

