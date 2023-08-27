#include<bits/stdc++.h>
using namespace std;

bool bipartite(vector<int>*edges,int n){
	queue<int> unfinished;
	unordered_set<int> s[2];
	unfinished.push(0);
	s[0].insert(0);
	while(unfinished.size()>0){
		int current = unfinished.front();
		unfinished.pop();
		int current_set = s[0].count(current) > 0 ? 0:1;
		for(int i=0;i<edges[current].size();i++){
			int neighbour = edges[current][i];
			if((s[0].count(neighbour) == 0) && (s[1].count(neighbour) == 0))  
			{
				s[1-current_set].insert(neighbour);
				unfinished.push(neighbour);
			}else if(s[current_set].count(neighbour)>0){
					return false;
			}				
		}
	}
}
/*
	unordered_set<int> sets[2];
	vector<int> pending;
	sets[0].insert(0);
	pending.push_back(0);
	while (pending.size() > 0) {
		int current = pending.back();
		pending.pop_back();
		int currentSet = sets[0].count(current) > 0 ? 0 : 1;
		for (int i = 0; i < edges[current].size(); i++) {
			int neighbor = edges[current][i];
			if (sets[0].count(neighbor) == 0 && sets[1].count(neighbor) == 0) {
				sets[1 - currentSet].insert(neighbor);
				pending.push_back(neighbor);
			} else if (sets[currentSet].count(neighbor) > 0) {
				return false;
			}
		}
	}






*/




int main(){
	while(1){
		int n,m;
		cin>>n;
		if(n==0){
			break;
		}
		cin>>m;
		vector<int>* edges= new vector<int>[n];
		for(int i=0;i<m;i++){
			int x,y;
			cin>>x>>y;
			edges[x].push_back(y);
			edges[y].push_back(x);
		}
		bool ans = bipartite(edges,n);
		delete[] edges;
		if(ans){
			cout<<"BICOLOURABLE"<<endl;
		}else{
			cout<<"NOT BICOLOURABLE"<<endl;
		}
	}
}
