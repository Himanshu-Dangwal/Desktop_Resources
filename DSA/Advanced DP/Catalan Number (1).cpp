//Catalan Number::
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
	
	for(int i=2;i<=n;i++)
		dp[i] = 0;
	
	for(int i=2;i<=n;i++){
		for(int j=0;j<i;j++){
			dp[i] += dp[j]*dp[i-j-1];
		}
	}
	
	cout<<dp[n]<<endl;
	return 0;
}

