//Generate Topological sort for a graph::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	int n,m,x,y;
	cin>>n>>m;
	
	vector<vector<int>> adj(n);
	vector<int> indegree(n,0);
	
	for(int i=0;i<m;i++){
		cin>>x>>y;
		adj[x].push_back(y);
		indegree[y]++;
	}
	
	queue<int> nodes;
	for(int i=0;i<n;i++){
		if(indegree[i] == 0){
			nodes.push(i);
		}
	}
	
	while(!q.empty()){
		int current = q.front();
		q.pop();
		cout<<current<<" ";
		for(int i=0;i<adj[current].size();i++){
			indegree[adj[current][i]]--;
			if(indegree[adj[current][i]] == 0)
				q.push(adj[current][i]);
		}
	}
	return 0;
}

