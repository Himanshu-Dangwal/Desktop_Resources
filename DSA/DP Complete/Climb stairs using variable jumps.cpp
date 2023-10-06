//Climb stairs with variable jumps::
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;cin>>arr[i++]);
	int dp[n+1];
	for(int i=0;i<=n;i++)
		dp[i] = 0;
	dp[n] = 1;
	for(int i=n-1;i>=0;i--){
		int val = arr[i];
		for(int j=1;j<=val;j++){
			if(i+j<=n)
				dp[i] += dp[i+j];
		}
	}
	cout<<dp[0]<<endl;
	return 0;
}

