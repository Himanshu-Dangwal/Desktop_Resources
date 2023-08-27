//Coin Change Combinations::
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	//Enter the denominations of coin we have::
	int arr[n];
	for(int i=0;i<n;cin>>arr[i++]);
	int k;
	cin>>k;
//	for k we have to check for total ways to give change::
	int dp[k+1];
	dp[0] = 1;
	for(int i=1;i<=k;i++){
		dp[i] = 0;
	}
	for(int i=0;i<n;i++){
		int curr_coin = arr[i];
		for(int j=curr_coin;j<=k;j++){
			dp[j] += dp[j-curr_coin]; 
		}
	}
	cout<<dp[k]<<endl;
	return 0;
}

