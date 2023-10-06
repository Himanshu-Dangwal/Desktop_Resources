#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

vector<int> adj[10000];
bool visited[10000;]
vector<int> st;
bool dfs(int src){
	visited[src] = ttrue;
	st[src] = 1;
	
	for(auto x : adj[src]){
		if(visited[x] && st[x])
			return true;
		if(!visited[x])
			dfs(x);	
	}
	st[src] = 0;
	return false;
}


int main(){
	//Input n,m 
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		
		adj[x].push_back(y);
	}
	
	bool cycle = false;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			if(dfs(i)){
				cycle = true;
				break;
			}
				
		}
	}
	
	if(cycle)	cout<<"Cycle Present";
	else cout<<"No CYcle";
	
	return 0;
}

