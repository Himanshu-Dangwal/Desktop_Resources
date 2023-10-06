#include<bits/stdc++.h>
#include<map>
using namespace std;

class graph{
	public :
		map<int,bool> visited;
		map<int,vector<int>> adj;
		void addedg(int v,int w);
		void DFS(int idx);
		void printgraph();
};



void graph::addedg(int v,int w)
{
	adj[v].push_back(w);
}


void graph::DFS(int v)
{
	visited[v]=true;
	cout<<v<<" ";
	
	vector<int>::iterator it;
	for(it=adj[v].begin();it!=adj[v].end();it++)
	{
		if(!visited[*it])
		DFS(*it);
	}
}

void graph::printgraph(){
	
	for(auto item : adj){
		vector<int> ans = item.second;
		for(int i=0;i<ans.size();i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	
}

int main()
{
	graph g;
	int n,e;
	cin>>n>>e;
	for(int i=0;i<e;i++)
	{
		int v,w;
		cin>>v>>w;
		g.addedg(v,w);
	}
	g.printgraph();
	cout<<endl;
	g.DFS(1);
}
