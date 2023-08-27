//Friends pairing problem::
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	cout<<endl;
	int dp[n+1];
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	
	for(int i=4;i<=n;i++){
		dp[i] = dp[i-1] + (i-1)*dp[i-2];
	}
	cout<<dp[n]<<endl;
	return 0;
}


