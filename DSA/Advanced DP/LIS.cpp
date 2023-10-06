//LIS
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int main(){
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int dp[n];
	
	dp[0] = 1;
	int max_val = INT_MIN;
	for(int i=1;i<n;i++){
		dp[i] = 1;
		for(int j=0;j<i;j++){
			if(arr[j] < arr[i]){
				dp[i] = max(dp[i],dp[j] + 1);
			}
		}
		max_val = max(max_val,dp[i]);
	}
	
	cout<<max_val<<endl;
	
	return 0;
}

