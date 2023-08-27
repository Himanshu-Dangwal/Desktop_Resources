//Detecting Cycle in a directed graph using stack::
#include<bits/stdc++.h>
using namespace std;

//bool isCycle(int sv,vector<vector<int>> &edges,vector<bool> &visited,vector<bool> &stack){
//	stack[sv]=true;
//	if(!visited[sv]){
//		visited[sv] = true;
//		for(int i=0;i<edges[sv].size();i++){
//			int neighbor = edges[sv][i];
//			if(!visited[neighbor] and isCycle(neighbor,edges,visited,stack)){
//				return true;
//			}
//			if(stack[neighbor] == true)
//				return true;	
//		}	
//	}
//	stack[sv] = false;
//	return false;
//}

bool isCycle(int src,vector<vector<int>> &edges,vector<bool>&visited,vector<bool>&s){
	
	if(!visited[src]){
		visited[src] = true;
		s[src] = true;
		for(auto i : edges[src]){
			if(!visited[i] && isCycle(i,edges,visited,s))
				return true;
			else if(s[i])
				return true;	
		}
	}
	s[src] = false;
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
	}
	bool cycle = false;
	vector<bool> visited(n,false);
	vector<bool> s(n,false);
	for(int i=0;i<n;i++){
		if(!visited[i] && isCycle(i,edges,visited,s));
			cycle = true;
	}
	if(cycle)
		cout<<"Cycle is present"<<endl;
	else
		cout<<"Cycle is not present"<<endl;
	return 0;	
}
