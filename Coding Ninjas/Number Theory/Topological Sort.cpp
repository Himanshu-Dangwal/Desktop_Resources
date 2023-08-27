//Topological Sort::
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> edges(n);
	vector<int> indegree(n,0);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		edges[x].push_back(y);
//		x --> y
		indegree[y]++;
	}
	queue<int> q;
	for(int i=0;i<n;i++){
		if(indegree[i] == 0)
			q.push(i);
	}
	while(!q.empty()){
		int current = q.front();
		q.pop();
		cout<<current<<" ";
		
		//Method 1
		
		for(int i=0;i<edges[current].size();i++){
			indegree[edges[current][i]]--;
			if(indegree[edges[current][i]] == 0){
				q.push(edges[current][i]);
			}
		}


		//Method 2
		
//		for(auto child : edges[current]){
//			
//			indegree[child]--;
//			if(indegree[child] == 0){
//				q.push(child);
//			}
//			
//		}
		
			
	}
	return 0;
}
