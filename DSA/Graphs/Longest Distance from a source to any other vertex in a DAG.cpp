//Longest Path in a Directed Acyclic Graph:::

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	
	int n,e;
	cin>>n>>e;
	
	vector<vector<pair<int,int>>> adj(n);
	
	for(int i=0;i<e;i++){
		
		int x,y,w;
		cin>>x>>y>>w;
		
		adj[x].push_back(make_pair(y,w));
		
	}
	
	vector<int> visited(n,0);
	vector<int> topological_rev_ordering;
	
	for(int i=0;i<n;i++){
		if(!visited[i]){
			topo(i,visited,topological_rev_ordering,adj);
		}
	}
	
	int source;
	cin>>source;
	
	int distance[n];
	for(int i=0;i<n;i++)
		distance[i] = INT_MIN;
	
	distance[source] = 0;
	
	for(int i=topological_rev_ordering.size()-1;i>=0;i--){
		
		if(distance[topological_rev_ordering[i]] != INT_MIN ){
			
			for(auto child : adj[topological_rev_ordering[i]]){
				
				int dest_vertex = child.first;
				int weight_edge = child.second;
				
				if(distance[dest_vertex] < distance[topological_rev_ordering[i]] + weight_edge){
					distance[dest_vertex] = distance[topological_rev_ordering[i]] + weight_edge;
				}
				
			}
			
		}
		
	}
		
	
	
	return 0;
}














