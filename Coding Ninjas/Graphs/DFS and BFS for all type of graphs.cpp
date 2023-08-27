//DFS and BFS for all type of graphs::::

#include<bits/stdc++.h>
using namepacse std;
//Bfs requires queue..Dfs can be implemented directly using recursion>>ans recursion takes place using stavk data structure:::
void printBFS(int **g,int sv,bool *visited){
	queue<int> q;
	q.push(sv);
	visited[sv] = true;
	while(!q.empty()){
		int currentVal = q.front();
		q.pop();
		cout<<currentVal<<endl;
		for(int i=0;i<v;i++){
			if(!visited[i] && g[currentVal][i]==1){
				q.push(i);
				visited[i] = true;
			}
		}
	}
}
void bFS(int **g,int v){
	bool *visited = new bool[v];
	for(int i=0;i<v;i++){
		visited[i] = false;
	}
	for(int i=0;i<v;i++){
		if(!visited[i]){
			printBFS(g,i,visited);
		}
	}
	delete []visited;
}
void printDFS(int **g,int sv,bool *visited){
	cout<<sv<<endl;
	visited[sv] = true;
	for(int i=0;i<v;i++){
		if(i==sv){continue;
		}
		if(visited[i]){continue;
		}
		if(!visited[i] && g[sv][i] == 1){
			printDFS(g,i,visited);
		}
	}
	
	return;	
}
void dFS(int **g,int v){
	bool *visited = new bool[v];
	for(int i=0;i<v;i++){
		visited[i] = false;
	}
	for(int i=0;i<v;i++){
		if(!visited[i]){
			printDFS(g,i,visited);
		}
	}
	delete[] visited;
	return;
}
int main(){
	int v,e;
	cin>>v>>e;
	int **g = new int*[v];
	for(int i=0;i<v;i++){
		g[i] = new int[v];
		for(int j=0;j<v;j++){
			g[i][j] = 0;
		}
	}
	int a,b;
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			cin>>a>>b;
			g[a][b] = 1;
			g[b][a] = 1;
		}
	}
	cout<<"USing DFS to print::"<<endl;
	dFS(g,v);
	cout<<"Usinf BFS to print::"<<endl;
	bFS(g,v);
	return 0;
	for(int i=0;i<v;i++){
		delete[] g[i];
	}
	delete[] g;
}
