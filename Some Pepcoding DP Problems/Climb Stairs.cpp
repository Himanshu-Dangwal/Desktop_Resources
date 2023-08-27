//Climb stairs Problem With 1 2 3 jumps allowed
//Total Ways to reah the nth stair:::
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int dp[n+1];
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	if(n<4){
		cout<<dp[n]<<endl;
		return 0;
	}
	for(int i=4;i<=n;i++){
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3]; 
	}
	cout<<dp[n]<<endl;
	return 0;
}

