//Partition Into Subsets::
/*
	We are given n persons and we have to divide them into k teams::
	We just need to calculate total number of ways of doing so::
*/	
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	cout<<endl;
	
	int dp[k+1][n+1];
	for(int i=0;i<=k;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0){
				dp[i][j] = 0;
			}else if(i > j){
				dp[i][j] = 0;
			}else if(i==j){
				dp[i][j] = 1;
			}else{
				dp[i][j] = dp[i][j-1]*i + dp[i-1][j-1];
			}
		}
	}
	cout<<dp[k][n]<<endl;
	
	return 0;
}

