//Best Time TO Buy And Sell Stocks K Transactions Allowed::
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;cin>>arr[i++]);
	int k;
	cin>>k;
	
	int dp[k+1][n];

	for(int t=0;t<=k;t++){
		int max_val = INT_MIN; 
		for(int d=0;d<n;d++){
			if(t==0 || d==0){
				dp[t][d] = 0;
				continue;
			}
			if((dp[t-1][d-1] - arr[d-1]) > max_val){
				max_val = dp[t-1][d-1] - arr[d-1];
			}
			dp[t][d] = max(dp[t][d-1],max_val + arr[d]);
		}
	}	
	cout<<dp[k][n-1]<<endl;

	return 0;
}




//	Method 1 :: O(n^3)
//	for(int t=0;t<=k;t++){
//		for(int d=0;d<n;d++){
//			if(t==0 || d==0){
//				dp[t][d] = 0;
//				continue;
//			}
//			int max_till_now = dp[t][d-1]; 
//			for(int pd=0;pd<d;pd++){
//				if((dp[t-1][pd]+arr[d]-arr[pd]) > max_till_now){
//					max_till_now = dp[t-1][pd]+arr[d]-arr[pd];
//				}
//			}
//			dp[t][d] = max_till_now;
//		}
//	}
//	Method 2:: O(n^2)






