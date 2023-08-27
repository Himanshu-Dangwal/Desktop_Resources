//Climb Stairs With Minimum Moves::
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;cin>>arr[i++]);
	
	int dp[n+1];
	dp[n] = 0;

	for(int i=n-1;i>=0;i--){
		int min_val = INT_MAX;
		int curr_val = arr[i];
		if(curr_val == 0){
			dp[i] = INT_MAX;
			continue;
		}
		for(int j=1;j<=cur_val && (i+j)<=n;j++){
			min_val = min(min_val,1+dp[i+j]);
		}
		dp[i] = min_val;
	}
	cout<<dp[0]<<endl;
	return 0;
}

