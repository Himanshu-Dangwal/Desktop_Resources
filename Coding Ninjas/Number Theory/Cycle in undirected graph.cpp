//Cycle Detection in Undirected Graph::
#include<bits/stdc++.h>
using namespace std;

bool isCycle(int src,vector<vector<int>> &edges,vector<bool> &visited,int parent){
	visited[src] = true;
	for(auto i: edges[src]){
		if(i!=parent){
			if(visited[i])
				return true;
			if(!visited[i] && isCycle(i,edges,visited,src))
				return true;	
		}	
	}
	return false;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> edges(n);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	vector<bool> visited(n,false);
	bool cycle = false;
	for(int i=0;i<n;i++){
		if(!visited[i] && isCycle(i,edges,visited,-1))
			cycle = true;
	}
	if(cycle)
		cout<<"Cycle is present"<<endl;
	else
		cout<<"Cycle is not present"<<endl;
	return 0;	
}
