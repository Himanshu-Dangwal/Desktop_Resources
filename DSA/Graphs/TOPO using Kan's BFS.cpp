#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

vector<int> adj[10000];
vector<int> topo;
queue<int> q;
vector<int> indegree;


int main(){
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		
		adj[x].push_back(y);
		++indegree[y];
	}
	
	for(int i=0;i<n;i++){
		if(!indegree[i])
			q.push(i);
	}
	
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		topo.push_back(curr);
		
		for(int x : adj[curr]){
			indegree[x]--;
			if(!indegree[x]) q.push(x);
		}
	}
	
	for(int i=0;i<topo.size();i++) cout<<topo[i]<<" ";
	
	return 0;
}

