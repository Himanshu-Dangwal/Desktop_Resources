//Scc best approach

#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100000];

void dfs(int start,stack<int> &finishedStack, bool *visited)
{
    visited[start] = true;
    for(int i = 0; i < graph[start].size(); i++)
    {
        int adj = graph[start][i];

        if(!visited[adj])
        {
            dfs(adj,finishedStack,visited);
        }
    }

    finishedStack.push(start);
}

void dfs2(int start,unordered_set<int> &visitSet)
{
    visitSet.insert(start);

    for(int i = 0; i < graph[start].size(); i++)
    {
        int adj = graph[start][i];

        if(visitSet.count(adj) == 0)
        {
            dfs2(adj,visitSet);
        }
    }
}

void getSCC(int n){
	stack<int> finishedTime;
	bool *visited = new bool[n];
	for(int i=0;i<n;i++){
		visited[i] = false;
	}
	for(int i=0;i<n;i++){
		if(!visited[i]){
			dfs(i,finishedTime,visited);
		}
	}
	unordered_set<int> visitSet;
	int count = 0;
	while(visitSet.size() < n){
		int element = finishedTime.top();
		finishedTime.pop();
		if(visitSet.count(element) == 0){
			dfs2(element,visitSet);
			count++;
		}
	}
	cout<<count<<endl;
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		graph[i].clear();
	}
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		graph[x-1].push_back(y-1);
	}
	getSCC(n);
}
