//Target Sum Subsets::
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int k;
	cin>>k;
	//A team of n players have to score k runs::
	//Check if they can score or not::
	int dp[n+1][k+1];
	//First row as 0::and then first column as 1;
	for(int i=0;i<=k;i++){
		dp[0][i] = 0;
	}
	
	for(int i=0;i<=n;i++){
		dp[i][0] = 1;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			dp[i][j] = dp[i-1][j];
			if(j-arr[i-1] >= 0){
				dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
			}
		}
	}
	cout<<dp[n][k]<<endl;
	return 0;
}

