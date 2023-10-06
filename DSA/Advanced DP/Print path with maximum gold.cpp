//Print path with maximum gold::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

struct Pair{
	int i,j;
	string psf;
	
	Pair(int i,int j,string s){
		this->i = i;
		this->j = j;
		this->psf = s;
	}
};

int main(){
	int n,m;
	cin>>n>>m;
	
	int arr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	
	
	int dp[n][m];
	for(int j=m-1;j>=0;j--){
		for(int i=0;i<n;i++){
			if(j == m-1){
				dp[i][j] = arr[i][j];
			}else if(i == 0){
				dp[i][j] = arr[i][j] + max(dp[i][j+1],dp[i+1][j+1]);
			}else if(i== n-1){
				dp[i][j] = arr[i][j] + max(dp[i][j+1],dp[i-1][j+1]);
			}else{
				dp[i][j] = arr[i][j] + max(dp[i][j+1],max(dp[i-1][j+1],dp[i+1][j+1]));
			}
		}
	}
	
	int max_gold = INT_MIN;
	for(int i=0;i<n;i++){
		if(dp[i][0] > max_gold){
			max_gold = dp[i][0];
		}
	}
		
	queue<Pair> q;	
		
	for(int i=0;i<n;i++){
		if(dp[i][0] == max_gold){
			string s = "" ;
			Pair t(i,0,to_string(i+1) + s);
			q.push(t);
		}
	}
	
	while(!q.empty()){
		Pair rem = q.front();
		q.pop();
		
		if(rem.j == m-1){
			cout<<rem.psf<<endl;
			continue;
		}
		
		if(rem.i == 0){
			int max_val = max(dp[rem.i][rem.j+1],dp[rem.i+1][rem.j+1]);
			
			if(dp[rem.i][rem.j+1] == max_val){
				Pair t(rem.i,rem.j+1,rem.psf + " d2");
				q.push(t);
			}
			
			if(dp[rem.i+1][rem.j+1] == max_val){
				Pair t(rem.i+1,rem.j+1,rem.psf + " d3");
				q.push(t);
			}
		}else if(rem.i == n-1){
			int max_val = max(dp[rem.i][rem.j+1],dp[rem.i-1][rem.j+1]);
			
			if(dp[rem.i][rem.j+1] == max_val){
				Pair t(rem.i,rem.j+1,rem.psf + " d2");
				q.push(t);
			}
			
			if(dp[rem.i-1][rem.j+1] == max_val){
				Pair t(rem.i-1,rem.j+1,rem.psf + " d1");
				q.push(t);
			}
		}else{
			int max_val = max(dp[rem.i][rem.j+1],max(dp[rem.i-1][rem.j+1],dp[rem.i+1][rem.j+1]));
			
			if(dp[rem.i][rem.j+1] == max_val){
				Pair t(rem.i,rem.j+1,rem.psf + " d2");
				q.push(t);
			}
			
			if(dp[rem.i-1][rem.j+1] == max_val){
				Pair t(rem.i-1,rem.j+1,rem.psf + " d1");
				q.push(t);
			}
			
			if(dp[rem.i+1][rem.j+1] == max_val){
				Pair t(rem.i+1,rem.j+1,rem.psf + " d3");
				q.push(t);
			}
		}
	}
	
	return 0;
}



















