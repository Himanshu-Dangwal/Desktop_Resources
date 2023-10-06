//Travelling Salesman Problem 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

//TC = O(n * 2^n)     NP  Hard  Problem   i.e Non Deterministic Polynomial Hard Problem


int tsp(int mask,int pos,vector<vector<int>> &adj,int visited_all,int n){
	
	if(mask == visited_all){
//		cout<<"Returning "<<adj[pos][0]<<endl;
		return adj[pos][0];
	}
		
	
	int ans = INT_MAX;
	
//	cout<<endl;
	
	for(int city = 0;city < n;city++){
		if((mask & (1<<city)) == 0){
			int curr_ans =  adj[pos][city] + tsp((mask | (1<<city)),city,adj,visited_all,n);
			
//			cout<<curr_ans<<endl;
			
			ans = min(ans,curr_ans);
		}
	}
	
	return ans;
}

int main(){
	
	int n;
	
	cin>>n;
	
	vector<vector<int>> adj(n,vector<int>(n,0));

	int visited_all = ((1<<n) - 1) ;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>adj[i][j];
		}
	}
	
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			cout<<adj[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	
	int mask = 1;
	int pos = 0;

	cout<<tsp(mask,pos,adj,visited_all,n)<<endl;
	
	return 0;
}

