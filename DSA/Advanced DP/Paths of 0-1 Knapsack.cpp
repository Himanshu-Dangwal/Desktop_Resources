//Paths of 0-1 Knapsack
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

struct Pair{
	int i,j;
	string psf;
	
	Pair(int x,int y,string s){
		this->i = x;
		this->j = y;
		this->psf = s;
	}
};

int main(){
	int n;
	cin>>n;
	
	int weights[n],values[n];
	
	for(int i=0;i<n;i++)
		cin>>weights[i];
		
	for(int i=0;i<n;i++)
		cin>>values[i];
		
	int max_weight;
	cin>>max_weight;
		
	int dp[n+1][max_weight+1];
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=max_weight;j++){
			dp[i][j] = 0;
		}
	}		
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=max_weight;j++){
			dp[i][j] = dp[i-1][j];
			
			if(j >= weights[i-1]){
				dp[i][j] = max(dp[i][j], values[i-1] + dp[i-1][j-weights[i-1]]);
			}
		}
	}
	
	cout<<dp[n][max_weight]<<endl;
	
	queue<Pair> q;
	string s = "";
	Pair t(n,max_weight,s);
	q.push(t);
	
	while(!q.empty()){
		Pair rem = q.front();
		q.pop();
		
		if(rem.i == 0 || rem.j == 0){
			cout<<rem.psf<<endl;
		}else{
			int exclude = dp[rem.i -1][rem.j];
			
			if(exclude == dp[rem.i][rem.j]){
				Pair t(rem.i-1,rem.j,rem.psf);
				q.push(t);
			}
			
			if(rem.j >= weights[rem.i - 1]){
				int include  = dp[rem.i-1][rem.j - weights[rem.i - 1]];
				if(include + values[rem.i-1] == dp[rem.i][rem.j]){
					Pair t(rem.i-1,rem.j - weights[rem.i-1],to_string(rem.i) + ' ' + rem.psf);
					q.push(t);
				}
			}
		}
	}
	
	return 0;
}













