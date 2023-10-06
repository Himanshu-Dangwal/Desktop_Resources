//Cycle in Directed Graph::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

bool isCycle(int src,vector<vector<int>> &a,vector<int>& visited,vector<int> &stack){
	stack[src] = 1;
	if(!visited[src]){
		visited[src] = 1;
		for(auto child : a[src]){
			if(!visited[child] && isCycle(child,a,visited,stack)){
				return true;
			}
			if(stack[child] == 1){
				return true;
			}
		}
	}
	stack[src] = 0;
	return false;
}

int main(){
	int n,m;
	cin>>n>>m;
	
	vector<vector<int>> a(n);
	
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		a[x].push_back(y);
	}
	
	bool cycle = false;
	
	vector<int> visited(n,0);
	vector<int> stack(n,0);
	
	for(int i=0;i<n;i++){
		if(!visited[i] && isCycle(i,a,visited,stack)){
			cycle = true;
		}
	}
	
	if(cycle){
		cout<<"Cycle is present"<<endl;
	}else{
		cout<<"Cycle is not present"<<endl;
	}

	return 0;
}

