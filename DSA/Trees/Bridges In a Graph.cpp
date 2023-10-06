//Bridges In a Graph:::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

vector<int> adj[100];
int visited[100],in[100],low[100];
int timer;

void dfs(int node,int par){
	visited[node] = 1;
	in[node] = low[node] = timer;
	timer++;
	
	for(auto child : adj[node]){
		if(child == par)
			continue;
		if(visited[child] == 1){
			low[node] = min(low[node],in[child]);
		}else{
			dfs(child,node);
			if(in[node] < low[child]){
				//It is a bridge::
				cout<<"There is a bridge between "<<node<<"->"<<child<<endl;
			}
			low[node] = min(low[node],low[child]);
		}	
	}
}


int main(){
	int n,m,x,y;
	cin>>n>>m;
	while(m--){
		cin>>x>>y , adj[x].push_back(y) ,adj[y].push_back(x);
	}
	
	dfs(1,-1);
}
