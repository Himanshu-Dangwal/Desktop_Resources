//Shortest Path in a DAG::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

void DFS_topo(bool* visited,int src,vector<vector<pair<int,int>>> &adj,vector<int> &rev_topo){
	
	visited[src] = true;
	
	for(auto child : adj[src]){
		if(!visited[child.first]){
			DFS_topo(visited,child.first,adj,rev_topo);
		}
	}
	
	rev_topo.push_back(src);
	
}


int main(){
	
	int v,e;
	cin>>v>>e;
	
	vector<vector<pair<int,int>>> adj(v);
	
	for(int i=0;i<e;i++){
		int x,y,z;
		cin>>x>>y>>z;
		
		adj[x].push_back(make_pair(y,z));
	}
	
	int src;
	cin>>src;
	
	bool* visited = new bool[v];
	for(int i=0;i<v;i++){
		visited[i] = false;
	}
	
	vector<int> rev_topo;
	
	for(int i=0;i<v;i++){
		if(!visited[i]){
			DFS_topo(visited,i,adj,rev_topo);
		}
	}
	
	cout<<"\nReverse Topo"<<endl;
	for(int i=0;i<v;i++){
		cout<<rev_topo[i]<<" ";
	}
	cout<<endl;
	
	vector<int> topo_sort;
	
	cout<<rev_topo.size()<<endl;
	
	int j=0;
	for(int i=v-1;i>=0;i--){
		cout<<"Inside Here"<<endl;
		topo_sort.push_back(rev_topo[i]); 
		j++;
	}
	
	
	
	cout<<"\n Topo"<<endl;
	for(int i=0;i<v;i++){
		cout<<topo_sort[i]<<" ";
	}
	cout<<endl;
//	for(int i=0;i<v;i++){
//		visited[i] = false;
//	}
	
	int *distance = new int[v];
	for(int i=0;i<v;i++){
		distance[i] = INT_MAX;
	}
	

	
	distance[src] = 0;
	
	for(int i=0;i<v;i++){
		
		int curr_vertex = topo_sort[i];
//		visited[curr_vertex] = true;
		if(distance[curr_vertex] != INT_MAX){
			for(auto child : adj[curr_vertex]){
				int v = child.first;
				int w = child.second;
				
				if(distance[v] > w + distance[curr_vertex]){
					distance[v] = w + distance[curr_vertex];
				}
			}
		}
		
	}
	
	for(int i=0;i<v;i++){
		cout<<distance[i]<<" ";
	}
	
	
	
	return 0;
}

