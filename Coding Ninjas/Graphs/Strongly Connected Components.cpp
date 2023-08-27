#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>* edges,int start,unordered_set<int>& visited,stack<int>& finishedTime){
	visited.insert(start);
	for(int i=0;i<edges[start].size();i++){
		int adjacent = edges[start][i];
		if(visited.count(adjacent) == 0){
			dfs(edges,adjacent,visited,finishedTime);
		}
	}
	finishedTime.push(start);
}

void dfs2(vector<int>* edgesT,int start,unordered_set<int>* component,unordered_set<int>& visited){
	visited.insert(start);
	component->insert(start);
	for(int i=0;i<edgesT[start].size();i++){
		int adjacent = edgesT[start][i];
		if(visited.count(adjacent) == 0){
			dfs2(edgesT,adjacent,component,visited);
		}
	}
}

unordered_set<unordered_set<int>*>* getSCC(vector<int>* edges,vector<int>* edgesT,int n){
	stack<int> finishedTime;
	unordered_set<int> visited;
	for(int i=0;i<n;i++){
		if(visited.count(i) == 0){
			dfs(edges,i,visited,finishedTime);
		}
	}
	visited.clear();
	unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
	while(finishedTime.size()!=0){
		int element = finishedTime.top();
		finishedTime.pop();
		if(visited.count(element) == 0){
			unordered_set<int>* component = new unordered_set<int>();
			dfs2(edgesT,element,component,visited);
			output->insert(component);
		}
	}
	return output;
}

int main(){
	int n; //Number of vertices::
	cin>>n;
	int m; //Number of edges::
	cin>>m;
	vector<int>* edges = new vector<int>[n];
	vector<int>* edgesT = new vector<int>[n];
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		edges[x-1].push_back(y-1);
		edgesT[y-1].push_back(x-1);
	}
	unordered_set<unordered_set<int>*>* components =  getSCC(edges,edgesT,n);
	unordered_set<unordered_set<int>*>::iterator it = components->begin();
	int count = 0;
	while(it!=components->end()){
		unordered_set<int>* component = *it;
		unordered_set<int>::iterator it2 = component->begin();
		while(it2!=component->end()){
//			cout<<*it2+1<<" ";
			it2++;
		}
		cout<<endl;
		it++;
		count++;
		delete component;
	}
	cout<<count-1;
	delete[] edges;
	delete[] edgesT;
	delete components;
}
