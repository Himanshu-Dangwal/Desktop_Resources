//Tiling with 2*1 tiles ::
/*
	Given a floor of n*2 .
		We have been Given the task to tile up thw floor with 2*1 size tiles::
*/		
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
	
	for(int i=3;i<=n;i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	cout<<dp[n];
	return 0;
}

