#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;


void getHamiltonianPaths(int src,vector<vector<int>> &adj,unordered_set<int> &visited,int osrc,string psf){    //orc = overall source
	
	
	if(visited.size() == adj.size() - 1){
		cout<<psf;
		
		bool flag = false;
		
		for(auto child : adj[src]){
			if(child == osrc){
	 			flag = true;     //It is a hamiltonian cycle::
			}
		}
		
		if(flag){
			cout<<"*"<<endl;
		}else{
			cout<<"."<<endl;
		}
		return;
	}
	
	visited.insert(src);
	for(auto child : adj[src]){
		if(visited.find(child) == visited.end()){
			getHamiltonianPaths(child,adj,visited,osrc,psf + to_string(child));
		}
	}
	visited.erase(src);
}

int main(){
	int n,e;
	cin>>n>>e;
	
	vector<vector<int>> adj(n);
	
	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y;
		
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	int src;
	cin>>src;
	
	unordered_set<int> visited;
	
	string psf = "";
	
	getHamiltonianPaths(src,adj,visited,src,psf + to_string(src));
	
	return 0;
}

