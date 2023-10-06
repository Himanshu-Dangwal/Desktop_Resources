//Target SUm subsets::
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
	int dp[n+1][target+1];
	//First row as zero and then first column as 1;
	for(int i=0;i<=target;i++){
		dp[0][i] = 0;
	}
	for(int i=0;i<=n;i++){
		dp[i][0] = 1;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=target;j++){
			dp[i][j] = dp[i-1][j];
			if(j >= arr[i-1]){
				dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
			}
		}
	}
	cout<<dp[n][target]<<endl;
	return 0;
}

