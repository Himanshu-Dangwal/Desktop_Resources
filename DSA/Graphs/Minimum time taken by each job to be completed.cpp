
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	int n,e;
	cin>>n>>e;
	
	
	vector<vector<int>> adj(n);
	
	vector<int> indegree(n,0);
	
	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y;
		
		adj[x-1].push_back(y-1);
		indegree[y-1]++;
	}
	
	queue<int> q;
	
	vector<int> ans(n,0);
	
	for(int i=0;i<n;i++){
		if(indegree[i] == 0){
			q.push(i);
			ans[i] = 1;
		}
	}
	
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		
		for(auto child : adj[curr]){
			indegree[child]--;
			if(indegree[child] == 0){
				ans[child] = ans[curr] + 1;
				q.push(child);
			}			
		}
	}
	cout<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	
	return 0;
}










