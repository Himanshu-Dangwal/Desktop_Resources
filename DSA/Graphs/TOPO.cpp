#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

vector<int> adj[10000];
bool visited[10000;]
stack<int> st;

void dfs(int src){
	visited[src] = true;
	
	for(int x : adj[src]){
		if(!visited[x])
			dfs(x);
	}
	
	st.push(src);
}


int main(){

	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		
		adj[x].push_back(y);
	}
	
	for(int i=0;i<n;i++){
		if(!visited[i])
			dfs(i);
	}
	
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	return 0;
}

