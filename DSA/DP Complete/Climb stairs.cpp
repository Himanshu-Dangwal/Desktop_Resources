//Climb stairs::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	int n;
	cin>>n;
	
	int dp[n+1];
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	
	for(int i=4;i<=n;i++){
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	}
	cout<<dp[n]<<endl;
	return 0;
}

