//Tiling an area of m*n by tiles of size m*1::
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	cout<<endl;
	int dp[n+1];
	for(int i=1;i<=n;i++){
		if(i<m){
			dp[i] = 1;
			continue;
		}
		if(i==m){
			dp[i] = 2;
		}else{
			dp[i] = dp[i-1] + dp[i-m];
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}

