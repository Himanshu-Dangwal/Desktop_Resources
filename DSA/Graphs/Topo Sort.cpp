#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

void DFS(vector<vector<int>>&adj,int src,stack<int>&st,vector<bool>&visited){
	visited[src] = true;
	
	for(auto x : adj[src]){
		if(!visited[x]){
			DFS(adj,x,st,visited);
		}
	}
	
	st.push(src);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,e;
	cin>>n>>e;
	
	vector<vector<int>> adj(n+1);
	
	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y;
		
		adj[x].push_back(y);
	}
	
	stack<int> st;

	vector<bool> visited(n+1,false);
	
	for(int i=0;i<n;i++){
		if(!visited[i]){
			DFS(adj,i,st,visited);	
		}
	}

	
	cout<<endl;
	
	while(!st.empty()){
		int x = st.top();
		cout<<x<<" ";
		st.pop();
	}
	
	return 0;
}

