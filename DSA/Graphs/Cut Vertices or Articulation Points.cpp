#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

vector<int> adj[10000];
int timer;
bool visited[10000];
int low[1000],in[1000];

void dfs(int node,int par){
	visited[node] = true;
	in[node] = low[node] = timer;
	timer++;
	
	for(int child : adj[node]){
		if(child == par) continue;
		if(visited[child])
			low[node] = min(low[node],in[child]);
		else{
			dfs(child,node);
			low[node] = min(low[node],low[child]);
			
			if(low[child] >= in[node] && parent != -1){
				//Bridge::
				cout<<"Articulation Point : "<<node<<endl;
			}	
		}	
	}
}


int main(){
	
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	dfs(1,-1);
	
	return 0;
}

