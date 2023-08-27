//Coin Change Permutations::
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int coins[n];
	for(int i=0;i<n;i++){
		cin>>coins[i];
	}
	int target;
	cin>>target;
	int dp[target+1];
	dp[0] = 1;
	for(int i=1;i<=target;i++){
		dp[i] = 0;
	}
	
	for(int amt = 1;amt<=target;amt++){
		for(int j=0;j<n;j++){
			int curr_coin = coins[j];
			if(amt-curr_coin >= 0)
				dp[amt] += dp[amt - curr_coin]; 
		}
	}
	cout<<dp[target]<<endl;
	return 0;
}

