
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

bool DFS(int src,vector<int> &visited,vector<int> &order,vector<vector<int>> &adj){
	
	visited[src] = 1;
	order[src] = 1;
	
	for(auto child : adj[src]){
		if(!visited[child]){
			bool ans = DFS(child,visited,order,adj);
			if(ans)
				return ans;
		}else if(order[child]){
			return true;
		}
	}
	order[src] = 0;
	return false;
}

bool isCycle(vector<vector<int>>&adj,int v){
	
	vector<int> visited(v,0);
	vector<int> order(v,0);
	
	for(int i=0;i<v;i++){
		if(!visited[i]){
			
			bool res = DFS(i,visited,order,adj);
			if(res)
				return true;
		}
	}
	return false;
}

int main(){
	int v,e;
	cin>>v>>e;
	
	vector<vector<int>> adj(v);
	
	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y;
		
		adj[x].push_back(y);
	}
	
	if(isCycle(adj,v)){
		cout<<"Cycle exist"<<endl;
	}else{
		cout<<"Cycle doesn't exists"<<endl;
	}
	
	return 0;
}


/*
	for(auto item : adj){
		for(int i=0;i<item.size;i++){
			cout<<item[i]<<" ";
		}	
		cout<<endl;
	}
*/		

