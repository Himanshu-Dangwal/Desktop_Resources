//Coin Change Combinations::
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
	int target;
	cin>>target;
	
	int dp[target+1];
	for(int i=0;i<=target;i++){
		dp[i] = 0;
	}
	dp[0] = 1;
	for(int i=0;i<n;i++){
		int curr_coin = arr[i];
		for(int j=curr_coin;j<=target;j++){
			dp[j] += dp[j-curr_coin];
		}
	}
//	for(int i=0;i<=target;i++){
//		cout<<dp[i]<<" ";
//	}
	cout<<dp[target]<<endl;
	return 0;
}

