#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

void dfs(int src,vector<vector<int>> &adj,bool *visited,int n){
	visited[src] = true;
	
	for(auto child : adj[src]){
		if(!visited[child]){
			dfs(child,adj,visited,n);
		}
	}
}

int main(){
	
	int n;
	cin>>n;s
	
	vector<vector<int>> adj(n);
	
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	bool* visited = new bool[n];
	for(int i=0;i<n;i++){
		visited[i] = false;
	}
	
	int c = 0;
	
	for(int i=0;i<n;i++){
		if(!visited[i]){
			dfs(i,adj,visited,n);
			c++;
		}
	}
	
	cout<<c-1<<endl;
	
	return 0;
}

