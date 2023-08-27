//DFS Traversal ::

#include<bits/stdc++.h>
using namespace std;

void print(int **graph,int v,bool *visited,int sv){
	cout<<sv<<endl;
	visited[sv] = true;
	for(int i=0;i<v;i++){
		if(sv == i){
			continue;
		}
		if(visited[i]){
			continue;
		}
		if(graph[sv][i] == 1){
			print(graph,v,visited,i);
		}
	}
	return;
}

int main(){
	iny v,e;
	cin>>v>>e;
	int **graph = new int *[v];
	for(int i=0;i<v;i++){
		graph[i] = new int[v];
		for(int j=0;j<v;j++){
			graph[i][j] = 0;
		}
	}
	int a,b;
	for(int i=0;i<e;i++){
		cin>>a>>b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	bool *visited = new bool[v];
	for(int i=0;i<v;i++){
		bool[i] = false;
	}
	print(graph,v,visited,0);  //arguments passed are = graph,no.0f vertices,bool array,start::
	return 0;
}
